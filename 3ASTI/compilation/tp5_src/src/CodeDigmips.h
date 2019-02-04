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
#ifndef __CODE_DIGMIPS_H
#define __CODE_DIGMIPS_H

#include <iostream>  //For the pretty-printer
#include <vector>

using namespace std;

enum test_t
  {
    E, NE, L, LE, G, GE
  };

//Pretty constructors
void add(int r_dest, int r1, int r2);
void sub(int r_dest, int r1, int r2);
void mul(int r_dest, int r1, int r2);
void div(int r_dest, int r1, int r2);
void ld(int r_dest, int r_base, int shift);
void st(int r_dest, int shift, int r_source);
void ble(int r1, int r2, string label);
void ldi(int r_dest, int constante);
void ldi_lo(int r_dest, string label);
void ldi_hi(int r_dest, string label);
void ja(int r1, int r2);
void j(string label);
void label(string label_id);

//Macros
void cjump(int r1, test_t relation, int r2, string target_label);
void copy(int r_dest, int r_source);
void push(int r);
void pop(int r);
void call(string function_label);
void ret(int n);

void push_all();
void pop_all();
void push_arp();
void pop_arp();
void mov_reg_sp(int r_dest); //r_dest <-- SP
void mov_sp_arp(); //SP <-- ARP
void mov_arp_sp(); //ARP <-- SP
void sub_sp_reg(int reg); //SP <-- SP - reg
void ld_arp(int reg, int shift); //reg <-- [ARP+shift]

#endif
