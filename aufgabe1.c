// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#include "aufgabe1.h"

void aufgabe1() {
	puts("# Aufgabe 1");

	puts("## Einlesen der Daten");
	FILE *fp = fopen("daten10.dat", "r");
	assert(fp);
	int size;
	assert(fscanf(fp, "%d\n", &size) == 1);
	double *data = malloc(size*size * sizeof(double));
	assert(data);
	matrix_load(fp, size, data);
	fclose(fp);

	puts("## Ausgabe der Rohdaten");
	matrix_print(data, size);

	free(data);
}

void matrix_load(FILE *fp, int size, double *data) {
	char *token;
	size_t buffer_size = 1000;
	char linebuffer[buffer_size];
	for (int line_id = 0; line_id < size; line_id++) {
		assert(fgets(linebuffer, buffer_size-1, fp));
		for (int column_id = 0; column_id < size; column_id++) {
			token = strtok(column_id == 0 ? linebuffer : NULL, " \t\n");
			data[line_id * size + column_id] = atof(token);
		}
	}
}

void matrix_print(double *data, int size) {
	for (int line_id = 0; line_id < size; line_id++) {
		for (int column_id = 0; column_id < size; column_id++) {
			printf(" %f", data[line_id * size + column_id]);
		}
		printf("\n");
	}
}
