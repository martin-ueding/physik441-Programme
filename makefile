# Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

CC = gcc
CFLAGS = -O3 -pedantic -std=c99 -Wall
LOADLIBES = -lm

cfiles := $(wildcard *.c)
ofiles := $(cfiles:.c=.o)

all: plot-2.pdf 3 plot-4.pdf

2: 2.o my_abs.o

3: 3.o

4: 4.o series.o

plot-2.pdf plot-4.pdf: plot sin.csv pi_a.csv pi_b.csv
	./$<

sin.csv: 2
	./$<

pi_a.csv pi_b.csv: 4
	./$<

dep:
	gcc -MM $(cfiles) > dep.makefile

-include dep.makefile

physik441-01-Martin_Ueding.tar:
	git archive --output "$@" master

.PHONY: clean
clean:
	$(RM) *.csv
	$(RM) *.o *.out
	$(RM) *.orig
	$(RM) *.pyc *.pyo
	$(RM) 2
	$(RM) 3
	$(RM) 4
	$(RM) dep.makefile
	$(RM) plot*.pdf
