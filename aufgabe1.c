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
	//matrix_print(data, size);
	matrix_save("out/1-raw.txt", data, size);
	printf("Spur: %g\n", trace(data, size));

	puts("## Maximieren der Diagonalen");
	maximize_diagonal(data, size);
	//matrix_print(data, size);
	matrix_save("out/1-minimized.txt", data, size);
	printf("Spur: %g\n", trace(data, size));

	puts("## Überprüfe Konvergenz");
	int convergent_count = check_convergence(data, size);
	printf("Konvergente Einträge: %d/%d\n", convergent_count, size);

	free(data);
}

int check_convergence(double *data, int size) {
	int convergent_count = 0;
	for (int line_id = 0; line_id < size; line_id++) {
		double sum = 0.;
		for (int column_id = 0; column_id < size; column_id++) {
			if (line_id == column_id) {
				continue;
			}
			sum += fabs(data[line_id * size + column_id]);
		}

		if (sum < data[line_id * size + line_id]) {
			convergent_count++;
		}
	}

	return convergent_count;
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

void matrix_save(char *filename, double *data, int size) {
	FILE *fp = fopen(filename, "w");
	assert(fp);
	for (int line_id = 0; line_id < size; line_id++) {
		for (int column_id = 0; column_id < size; column_id++) {
			fprintf(fp, " %f", data[line_id * size + column_id]);
		}
		fprintf(fp, "\n");
	}
	fclose(fp);
}

void maximize_diagonal(double *data, int size) {
	// Iterate through the columns ...
	for (int column_id = 0; column_id < size; column_id++) {
		// XXX Negative infinity should be used here for initialization.
		double largest = -1e100;
		int largest_id = -1;
		// Find the largest entry in this column.
		for (int line_id = 0; line_id < size; line_id++) {
			double val = data[line_id * size + column_id];
			if (val > largest) {
				largest = val;
				largest_id = line_id;
			}
		}
		assert(largest_id >= 0);

		// Swap the line with the largest entry in this column with the current line.
		swap_lines(data, size, largest_id, column_id);
	}
}

void swap_lines(double *data, int size, int source, int target) {
	if (source == target) {
		return;
	}
	
	printf("Swapping %d with %d\n", source, target);
	double buffer[size];
	for (int column_id = 0; column_id < size; column_id++) {
		buffer[column_id] = data[target * size + column_id];
	}
	for (int column_id = 0; column_id < size; column_id++) {
		data[target * size + column_id] = data[source * size + column_id];
	}
	for (int column_id = 0; column_id < size; column_id++) {
		data[source * size + column_id] = buffer[column_id];
	}
}

double trace(double *data, int size) {
	double result = 0.;
	for (int column_id = 0; column_id < size; column_id++) {
		result += data[column_id * size + column_id];
	}
	return result;
}
