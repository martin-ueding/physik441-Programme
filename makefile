# Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

CC = gcc
CFLAGS = -O3 -pedantic -std=c99 -Wall
LOADLIBES = -lm

cfiles := $(wildcard *.c)
ofiles := $(cfiles:.c=.o)

all: 1 2
	@echo
	@echo "Ausgabe Programm 1"
	./1
	@echo
	@echo "Ausgabe Programm 2"
	./2

1: 1.o bisect.o

2: 2.o bisect.o

dep:
	gcc -MM $(cfiles) > dep.makefile
	cat dep.makefile

-include dep.makefile

physik441-02-Martin_Ueding.tar:
	git archive --output "$@" master

.PHONY: clean
clean:
	$(RM) *.csv
	$(RM) *.o *.out
	$(RM) *.orig
	$(RM) *.pyc *.pyo
	$(RM) 1
	$(RM) 2
	$(RM) dep.makefile
	$(RM) plot*.pdf
