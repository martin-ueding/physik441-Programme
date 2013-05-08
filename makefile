# Copyright © 2013 Martin Ueding <dev@martin-ueding.de>
# Abgabe zusammen mit Jan Weber

CC = g++
CPPFLAGS = -O3 -pedantic -std=c++11 -Wall
LOADLIBES = -lcppunit

c_files := $(wildcard *.cpp)
o_files := $(c_files:.cpp=.o)

program_c_files := $(filter-out test_%, $(c_files))
program_o_files := $(program_c_files:.cpp=.o)

test_c_files := $(filter test_%, $(c_files))
test_o_files := $(test_c_files:.cpp=.o)

all: main plot
	@echo
	@echo "Ausgabe Programm"
	@echo
	time ./$<
	@echo
	./plot

dep:
	gcc -MM $(c_files) > dep.makefile
	cat dep.makefile

html: main
	./$< > output.txt
	doxygen

main: $(program_o_files)

physik441-03-Ueding_Weber.tar: doc
	git archive --output "$@" master
	tar --append -f "$@" html

test: test_main
	./$<

test_main: $(filter-out main.o,$(o_files))

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
	$(RM) plot*.pdf
	$(RM) tags
	$(RM) type_main
