#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H
// contain the headers I need
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// contain the struct typedef
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// define functions to be used
FILE import_file(char filename[], FITNESS_DATA data[], int count);
void display_total_num(int count);
void fewest_steps(FITNESS_DATA data[], int count);
void largest_steps(FITNESS_DATA data[], int count);
void mean(FITNESS_DATA data[], int count);
void above500(FITNESS_DATA data[], int count);

#endif