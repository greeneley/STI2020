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
#include "Attributes.h"

LhsExpr::LhsExpr(int result, int address, Type* t)
{ result_register = result; address_register = address; type = t; }


//Pretty-constructor 
LhsExpr* lhs(int result_register, int address_register, Type* type)
{ return new LhsExpr(result_register, address_register, type); }


RhsExpr::RhsExpr(int result, Type* t)
{ result_register = result; type = t; }


//Pretty-constructor 
RhsExpr* rhs(int result_register, Type* type)
{ return new RhsExpr(result_register, type); }
