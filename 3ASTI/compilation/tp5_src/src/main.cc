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
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <fstream> //for .asm output

//Interface with Flex & Bison
extern FILE *yyin;              //from Flex
extern int yyparse(void);       //from Bison
extern int line_number;         //

using namespace std;

void help()
{
  cerr << "usage: digcc file.c" << endl;
  exit(1);
}

ofstream asm_output;

int main(int argc, char** argv)
{
  if(argc != 2)
    help();

  //Open .asm file
  char* input_file = strdup(argv[1]);
  int len = strlen(input_file);
  input_file[len-1] = 0; //remove final 'c'
  string output_file = string(input_file);
  output_file += "asm";
  asm_output.open(output_file.c_str());

  yyin = fopen(argv[1],"r");
  if(yyin == 0)
    {
      cerr << "File not found: " << argv[1] << endl;
      exit(1);
    }

  line_number = 1;

  //Compile...
  int bison_return_code = yyparse();

  //Close .asm file
  asm_output.close();

  //Concat the runtime library to the asm file...
  string add_runtime_command = "cat ";
  add_runtime_command += output_file;
  add_runtime_command += " runtime.asm > ";
  add_runtime_command += output_file;
  add_runtime_command += ".swap";
  system(add_runtime_command.c_str());

  add_runtime_command = "mv ";
  add_runtime_command += output_file;
  add_runtime_command += ".swap ";
  add_runtime_command += output_file;
  system(add_runtime_command.c_str());
}
