// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>
// Licensed under The MIT License

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "aufgabe1.h"
#include "aufgabe2.h"
#include "aufgabe3.h"

extern char *optarg;
extern int optind, opterr, optopt;

typedef void (*aufgabe_t)();

int main(int argc, char **argv) {
	char c;
	while ((c = getopt(argc, argv, "a")) != -1) {
		switch (c) {
			case 'a':
				puts("a");
				break;
		}
	}

	aufgabe_t aufgaben[5] = {aufgabe1, aufgabe2, aufgabe3};

	if (argc > 1) {
		for (int arg_id = 1; arg_id < argc; arg_id++) {
			aufgaben[atoi(argv[arg_id]) - 1]();
		}
	}
	else {
		for (int aufgabe_id = 0; aufgabe_id < 5; aufgabe_id++) {
			aufgabe_t aufgabe = aufgaben[aufgabe_id];
			if (aufgabe) {
				aufgabe();
			}
		}
	}

	return 0;
}
