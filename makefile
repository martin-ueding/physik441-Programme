# Copyright © 2013 Martin Ueding <dev@martin-ueding.de>
# Abgabe zusammen mit Jan Weber

CC = gcc
CPPFLAGS = -g -pedantic -std=c99 -Wall
LOADLIBES = -lm

c_files := $(wildcard *.c)
o_files := $(c_files:.c=.o)

all: main

dep:
	gcc -MM $(c_files) > dep.makefile
	cat dep.makefile

html: output.txt plot
	doxygen

output.txt: main plot
	./main | tee $@
	./plot | tee -a $@

main: $(o_files)

physik441-05-Ueding_Weber.tar: html
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
	$(RM) dep.makefile
	$(RM) main
	$(RM) output.txt
	$(RM) out-*
	$(RM) tags
	$(RM) type_main
