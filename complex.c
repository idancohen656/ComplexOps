#include "complex.h"



void read_comp(complex *A, double x, double y)
{
	A->a = x;
	A->b = y;
}
void print_comp(complex *A)
{
	printf("( %.2f ) + ( %.2f )i\n", A->a , A->b);
}
complex add_comp(complex *A, complex *B)
{
	complex C;
	C.a = A->a + B->a;
	C.b = A->b + B->b;

	print_comp(&C);

	return C;
}
complex sub_comp(complex *A, complex *B)
{
	A->a -= B->a;
	A->b -= B->b;

	print_comp(A);

	return *A;
}
complex mult_comp_real(complex *A, double x)
{
	A->a = x*A->a;
	A->b = x*A->b;

	print_comp(A);

	return *A;
}
complex mult_comp_img(complex *A, double x)
{
	A->a = -x*A->b;
	A->b =  x*A->a;

	print_comp(A);

	return *A;

}
complex mult_comp_comp(complex *A, complex *B)
{
	complex C;
	C.a = A->a*B->a - A->b*B->b;
	C.b = A->a*B->b + A->b*B->a;

	print_comp(&C);

	return C;
}
double abs_comp(complex *A)
{
	double x;
	x = sqrt(pow(A->a,2)+pow(A->b,2));
	printf("%.2f\n", x);
	return x;
}
void stop()
{
	exit(0);
}





