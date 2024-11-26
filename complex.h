#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>


#define START_OVER 	{\
			memset(command, 0, sizeof(command));\
        		memset(operation, 0, sizeof(operation));\
			memset(str, 0, sizeof(str));\
        		length = 0;\
        		state = START;\
			goto start;\
			}

typedef enum {COMMA, OPERATION, OPERATOR, START}status;


typedef struct  {
		double a;
		double b;
		} complex;

complex A,B,C,D,E,F;



void read_comp(complex *A, double x, double y);
void print_comp(complex *A);
complex add_comp(complex* A, complex *B);
complex sub_comp(complex *A, complex *B);
complex mult_comp_real(complex *A, double x);
complex mult_comp_img(complex *A, double x);
complex mult_comp_comp(complex *A, complex *B);
double abs_comp(complex *A);
void stop();

