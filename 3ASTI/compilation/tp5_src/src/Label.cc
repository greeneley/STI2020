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
#include "Label.h"

#include <stdlib.h> //for exit()
#include <sstream>

#include <map>
#include <vector>

map<string,int> last_label;
vector<string> label_stack;

void reset_labels()
{
  last_label.erase(last_label.begin(),last_label.end());
  label_stack.resize(0);
}

string new_label(string prefix)
{
  string result;
  stringstream sstream;

  if(last_label.find(prefix) == last_label.end())
    last_label[prefix] = 0;

  sstream << prefix << "_" << last_label[prefix];
  sstream >> result; //No simple conversion int->string in C++ ...

  last_label[prefix]++;

  return result;
}

void push_label(string label)
{
  label_stack.push_back(label);
}

string pop_label()
{
  if(label_stack.size() == 0)
    {
      cerr << "Label::pop_label(): empty stack" << endl;
      exit(1);
    }

  string result = label_stack.back();
  label_stack.pop_back();
  
  return result;
}
