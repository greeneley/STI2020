#ifndef __BACKEND_H
#define __BACKEND_H

#include <string>

using namespace std;

void push(int address);
void mpush(int imm);
void pop(int address);

void add();
void sub();
void mul();
void div();

void testg();
void testne();

void label(string label);
void jz(string label);
void jmp(string label);

void stop();

void alloc(int size);
void free();

//
// Runtime handling
//

void call_runtime(string service);
void raw(string asm_code);

#endif
