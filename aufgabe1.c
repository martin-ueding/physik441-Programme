// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#include "aufgabe1.h"

void aufgabe1() {
	puts("# Aufgabe 1");

	FILE *fp = fopen("daten10.dat", "r");
	assert(fp);
	int size;
	assert(fscanf(fp, "%d\n", &size) == 1);
	double data[size][size];
	char *token;
	size_t buffer_size = 1000;
	char linebuffer[buffer_size];
	for (int line_id = 0; line_id < size; line_id++) {
		fgets(linebuffer, buffer_size-1, fp);
		for (int column_id = 0; column_id < size; column_id++) {
			token = strtok(linebuffer, " \t\n");
			data[line_id][column_id] = atof(token);
		}
	}
	fclose(fp);
}
