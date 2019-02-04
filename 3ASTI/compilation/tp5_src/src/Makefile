#############################################################################
# D Makefile, written by Christophe Alias
#############################################################################

OBJS            = Label.o Register.o Type.o SymbolTable.o Attributes.o \
		CodeDigmips.o parser.o lexer.o main.o 


BIN             = ../bin/digcc

DEBUG		= -g -DDEBUG

all: $(OBJS)
	g++-4.7 $(DEBUG) $(OBJS) -lfl -lm -o $(BIN)

%.o: %.cc
	g++-4.7 $(DEBUG) -c $<

clean:
	-rm -f $(OBJS) parser.cc parser.h lexer.cc *~ \#*

realclean:
	$(MAKE) clean
	-rm -f $(BIN)

parser.cc: parser.ypp
	bison --defines=parser.h --report=lookahead --report-file=bison_report -o parser.cc parser.ypp

lexer.cc: lexer.l
	flex -o lexer.cc lexer.l

