#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Prototypes
void pow_int(int *base, int exponent);
void pow_float(float *base, int exponent);
void pow_double(double *base, int exponent);
void pow_void(void *base, int exponent, int type);

int main(int argc, char const *argv[]){
	int *pi;
	int vi = 2;
	pi = &vi;

	float *pf;
	float vf = 2;
	pf = &vf;

	double *pd;
	double vd = 2;
	pd = &vd;

	pow_int(pi, 2);
	pow_float(pf, 2);
	pow_double(pd, 2);

	void *pv;
	pv = &vi;
	pow_void(pv, 2, 0);
	printf("VOID POINTER INT:    %d\n", *((int*)pv));
	pv = &vf;
	pow_void(pv, 2, 1);
	printf("VOID POINTER FLOAT:  %f\n", *((float*)pv));
	pv = &vd;
	pow_void(pv, 2, 2);
	printf("VOID POINTER DOUBLE: %f\n", *((double*)pv));
	printf("POINTER INT:         %d\n", *pi);
	printf("POINTER FLOAT:       %f\n", *pf);
	printf("POINTER DOUBLE:      %f\n", *pd);
	return EXIT_SUCCESS;
}

void pow_int(int *base, int exponent){	
	*base = pow(*base, exponent);
}

void pow_float(float *base, int exponent){	
	*base = pow(*base, exponent);
}

void pow_double(double *base, int exponent){	
	*base = pow(*base, exponent);
}

// type  0 = int 	1 = float 	2 = double
void pow_void(void *base, int exponent, int type){
	int i;
	float f;
	double d;
	switch(type){
		case 0:
			i = pow( *((int*) base), exponent);
			base = &i;
		case 1:
			f = pow( *((float*) base), 	exponent);
			base = &f;
		case 2:
			d = pow( *((double*) base), exponent);
			base = &d;
	}
}

