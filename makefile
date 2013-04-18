# Copyright © 2013 Martin Ueding <dev@martin-ueding.de>
# Abgabe zusammen mit Jan Weber

CC = g++
CFLAGS = -O3 -pedantic -std=c++11 -Wall

cfiles := $(wildcard *.cpp)
ofiles := $(cfiles:.cpp=.o)

all: main
	@echo
	@echo "Ausgabe Programm"
	./$<

main: $(ofiles)

dep:
	gcc -MM $(cfiles) > dep.makefile
	cat dep.makefile

-include dep.makefile

physik441-02-Ueding_Weber.tar: doc
	git archive --output "$@" master
	tar --append -f "$@" html

doc:
	doxygen

.PHONY: clean
clean:
	$(RM) *.csv
	$(RM) *.o *.out
	$(RM) *.orig
	$(RM) *.pyc *.pyo
	$(RM) *.tar
	$(RM) dep.makefile
	$(RM) main
	$(RM) plot*.pdf
