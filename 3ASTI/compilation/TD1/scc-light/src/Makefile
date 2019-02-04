#############################################################################
# D Makefile, written by Christophe Alias
#############################################################################

OBJS            = Label.o SymbolTable.o Backend-stack.o parser.o lexer.o main.o 

BIN             = ../bin/scc

all: $(OBJS)
	g++ $(DEBUG) $(OBJS) -lfl -lm -o $(BIN)

%.o: %.cc
	g++ $(DEBUG) -c $<

clean:
	-rm -f *.o parser.cc parser.h lexer.cc bison_report *~ \#*

realclean:
	$(MAKE) clean
	-rm -f $(BIN)

parser.cc: parser.ypp
	bison --defines=parser.h --report=lookahead --report-file=bison_report -o parser.cc parser.ypp

lexer.cc: lexer.l
	flex -o lexer.cc lexer.l

