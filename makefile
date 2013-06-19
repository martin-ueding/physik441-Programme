# Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

CC = gcc
CFLAGS = -O3 -pedantic -std=c99 -Wall
LOADLIBES = -lm

c_files := $(wildcard *.c)
o_files := $(c_files:.c=.o)

all: out main

dep:
	gcc -MM $(c_files) > dep.makefile
	cat dep.makefile

out:
	mkdir -p "$@"

html: out/output.txt plot
	doxygen

out/output.txt: main plot
	./main | tee $@
	echo >> $@
	./plot | tee -a $@

main: $(o_files)

physik441-07-Ueding.tar: html
	git archive --output "$@" master
	tar --append -f "$@" html

-include dep.makefile

.PHONY: clean
clean:
	$(RM) *.csv
	$(RM) *.o *.out
	$(RM) *.orig
	$(RM) *.pyc *.pyo
	$(RM) *.tar
	$(RM) -r html
	$(RM) -r out
	$(RM) dep.makefile
	$(RM) main
	$(RM) tags
