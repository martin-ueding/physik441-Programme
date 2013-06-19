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

html: out/output-main.txt out/output-plot.txt README.dox
	doxygen

out/output-main.txt: main
	./main | tee $@

out/output-plot.txt: out/output-main.txt plot
	./plot | tee $@

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
