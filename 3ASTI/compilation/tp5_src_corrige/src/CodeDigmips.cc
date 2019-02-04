/*****************************************************************************
 *                DigCC: a minimal C compiler for DigMIPS                    *
 ***************************************************************************** 
 *                                                                           *
 * Copyright (c) 2012 Christophe Alias                                       *
 *                                                                           *
 * This program is free software; you can redistribute it and/or modify it   *
 * under the terms of the GNU General Public License as published by the     *
 * Free Software Foundation; either version 2 of the License, or (at your    * 
 * option) any later version.                                                *
 *                                                                           *
 * This program is distributed in the hope that it will be useful, but       *
 * WITHOUT ANY WARRANTY; without even the implied warranty of                *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General  *
 * Public License for more details.                                          *
 *                                                                           *
 * You should have received a copy of the GNU General Public License along   *
 * with this program; if not, write to the Free Software Foundation, Inc.,   *
 * 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.                 *
 *                                                                           *
 * Written by Christophe Alias, Christophe.Alias@ens-lyon.fr                 *
 *                                                                           *
 *****************************************************************************/
#include "CodeDigmips.h"

#include <iostream>  //For the pretty-printer
#include <sstream> //for to_string()
#include <stdlib.h>  //for exit()

#include "Register.h"
#include "Label.h"

#define SPILL0 0
#define SPILL1 1
#define RETURN_REGISTER 2
#define SP 6
#define ARP 7

using namespace std;

//Pretty constructors
void add(int r_dest, int r1, int r2)
{
  cout << "  add r" << r_dest << ", r" << r1 << ", r" << r2 << endl;
}

void sub(int r_dest, int r1, int r2)
{
  cout << "  sub r" << r_dest << ", r" << r1 << ", r" << r2 << endl;
}

void mul(int r_dest, int r1, int r2)
{
  push(r1);
  push(r2);
  call("__mul");
  copy(r_dest,RETURN_REGISTER);
}

void div(int r_dest, int r1, int r2)
{
  push(r1);
  push(r2);
  call("__div");
  copy(r_dest,RETURN_REGISTER);
}

void ld(int r_dest, int r_base, int shift)
{
  if(shift >= 0)
    cout << "  ld r" << r_dest << ", [r" << r_base << " + " << shift << "]" << endl;
  else
    cout << "  ld r" << r_dest << ", [r" << r_base << " - " << -1*shift << "]" << endl;
}

void st(int r_dest, int shift, int r_source)
{
  if(shift >= 0)
    cout << "  st r" << r_dest << ", [r" << r_dest << " + " << shift << "]" << endl;
  else
    cout << "  st r" << r_dest << ", [r" << r_dest << " - " << -1*shift << "]" << endl;
}

void ble(int r1, int r2, string label)
{
  cout << "  ble r" << r1 << ", r" << r2 << ", " << label << endl;
}

void ldi(int r_dest, int constante)
{
  cout << "  ldi r" << r_dest << ", " << constante << endl;
}

void ldi_lo(int r_dest, string label)
{
  cout << "  ldi r" << r_dest << ", lo(" << label << ")" << endl;
}

void ldi_hi(int r_dest, string label)
{
  cout << "  ldi r" << r_dest << ", hi(" << label << ")" << endl;
}

void ja(int r1, int r2)
{
  cout << "  ja r" << r1 << ", r" << r2 << endl;
}

void j(string label)
{
  cout << "  j " << label << endl;
}

void label(string label_name)
{
  cout << label_name << ":" << endl;
}

void cjump(int r1, test_t test, int r2, string target_label)
{
  if(test == LE)
    ble(r1,r2,target_label);

  if(test == GE)
    ble(r2,r1,target_label);

  if(test == L)
    {
      int r2_minus_1 = new_register();
      int r_one = new_register();
      ldi(r_one,1);
      sub(r2_minus_1,r2,r_one);
      ble(r1,r2_minus_1,target_label);
    }

  if(test == G)
    cjump(r2,L,r1,target_label);

  if(test == E)
    {
      string label_le = new_label("lower");
      string label_neq = new_label("not_equal");
      ble(r1,r2,label_le);
      j(label_neq);
      label(label_le);
      ble(r2,r1,target_label);
      label(label_neq);      
    }

  if(test == NE)
    {
      string label_le = new_label("lower");
      string label_eq = new_label("equal");
      ble(r1,r2,label_le);
      j(target_label);
      label(label_le);
      ble(r2,r1,label_eq);
      j(target_label);
      label(label_eq);      
    }
}

void copy(int r_dest, int r_source)
{
  ldi(0,0); //r0 = 0
  add(r_dest,r_source,0);
}

void push(int r)
{
  int r_one = new_register();
  ldi(r_one,1);

  st(SP,0,r);
  //[SP] = r

  sub(SP,SP,r_one);
  //SP = SP - 1
}

void pop(int r)
{
  int r_one = new_register();
  ldi(r_one,1);

  add(SP,SP,r_one);
  //SP = SP + 1

  ld(r,SP,0);
  //r = [SP]
}

void call(string function_label)
{
  string label_ret = new_label("return_point");
  int r_lo = new_register();
  int r_hi = new_register();

  ldi_lo(r_lo,label_ret);
  ldi_hi(r_hi,label_ret);
  push(r_lo);
  //push lo(label_ret)
  push(r_hi);
  //push hi(label_ret)
  j(function_label);
  //j label
  label(label_ret);
  //label_ret:
}

void ret(int n)
{
  ldi(SPILL0,n+2);
  //r0 = n+2
  add(SP,SP,SPILL0);
  //SP = SP + (n+2)
  ld(SPILL0,SP,-1*(n+1));
  //r0 = [SP-(n+1)] (=hi)
  ld(SPILL1,SP,-1*n);
  //r0 = [SP-(n+1)] (=lo)
  ja(SPILL0,SPILL1);
  //RET
}


void mov_reg_sp(int r_dest)
{
  copy(r_dest,SP);
}

void mov_arp_sp()
{
  copy(ARP,SP);
}

void mov_sp_arp()
{
  copy(SP,ARP);
}

void sub_sp_reg(int reg)
{
  sub(SP,SP,reg);
}

void push_all()
{
  cout << "  push_all" << endl;
}

void pop_all()
{
  cout << "  pop_all" << endl;
}

void push_arp()
{
  push(ARP);
}

void pop_arp()
{
  pop(ARP);
}

void ld_arp(int reg, int shift)
{
  ld(reg,ARP,shift);
}
