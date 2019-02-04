%.out: %.o
	gcc -m64 -o $@ $<

%.o: %.asm
	nasm -f elf64 $<

%.asm: %.c
	../bin/scc $<

%.o: %.c

clean:
	-rm -f *.o *~

realclean:
	$(MAKE) clean
	-rm -f *.out

