# Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

CC = gcc
CFLAGS = -O3 -pedantic -std=c99 -Wall
LOADLIBES = -lm

cfiles := $(wildcard *.c)
ofiles := $(cfiles:.c=.o)

all: plot.pdf

2: 2.o my_abs.o

plot.pdf: plot sin.csv
	./$<

sin.csv: 2
	./$<

dep:
	gcc -MM $(cfiles) > dep.makefile

-include dep.makefile

.PHONY: clean
clean:
	$(RM) *.o *.out
	$(RM) *.orig
	$(RM) *.pyc *.pyo
	$(RM) 2
	$(RM) dep.makefile
	$(RM) plot.pdf
