#include <stdio.h>
#include <stdlib.h>

void pow_int(int* base, int exponent);
void pow_float(float* base, int exponent);
void pow_double(double* base, int exponent);
void pow_void(void* base, int exponent, int type);	// Wird benötigt um zu wissen auf welchen Datentyp man casten muss

int main(int argc, char** args)
{
	int baseI = 2;
	float baseF = 3.6;
	double baseD = 4.53;

	int exp = 4;

	printf("Integer Base: %i\n",baseI);
	printf("Float Base: %f\n", baseF);
	printf("Double Base %lf\n\n", baseD);
	printf("Exponent: %i\n\n", exp);

	int* iptr = &baseI;
	float* fptr = &baseF;
	double* dptr = &baseD;
	void* vptr;
	

	pow_int(iptr,exp);
	printf("Calculated Integer: %i\n", baseI);
	pow_float(fptr,exp);
	printf("Calculated Float: %f\n", baseF);
	pow_double(dptr,exp);
	printf("Calculated Double: %lf\n\n", baseD);

	// Reset Values
	int type = 0; // 1 = int, 2 = float, 3 = double
	baseI = 2;
	baseF = 3.6;
	baseD = 4.53;

	vptr = &baseI;
	type = 1;
	pow_void(vptr,exp,type);
	printf("Calculated with Void-Pointer: %i\n", baseI);
	vptr = &baseF;
	type = 2;
	pow_void(vptr,exp,type);
	printf("Calculated with Void-Pointer: %f\n", baseF);
	vptr = &baseD;
	type = 3;
	pow_void(vptr,exp,type);
	printf("Calculated with Void-Pointer: %lf\n", baseD);

	return EXIT_SUCCESS;
}


void pow_int(int* base, int exponent){
	int temp = *base;
	int temp2 = temp;

	for (int i = 1; i < exponent; ++i)
	{	
		temp = temp*temp2;
		
	}
	*base = temp;
	return;
}


void pow_float(float* base, int exponent){
	float temp = *base;
	float temp2 = temp;

	for (int i = 1; i < exponent; ++i)
	{	
		temp = temp*temp2;
		
	}
	*base = temp;
	return;
}


void pow_double(double* base, int exponent){
	double temp = *base;
	double temp2 = temp;

	for (int i = 1; i < exponent; ++i)
	{	
		temp = temp*temp2;
		
	}
	*base = temp;
	return;
}


void pow_void(void* base, int exponent, int type){

	if (type == 1)
	{
		int* ptr = (int*)base;
		int temp = *ptr;;
		int temp2 = temp;
		for (int i = 1; i < exponent; ++i)
		{	
			temp = temp*temp2;
		}
		ptr = &temp;
		
		*(int*)base = *ptr;
		return;
	}else if(type == 2) {
		float* ptr = (float*)base;
		float temp = *ptr;;
		float temp2 = temp;
		for (int i = 1; i < exponent; ++i)
		{	
			temp = temp*temp2;
		}
		ptr = &temp;
		
		*(float*)base = *ptr;
		return;
	} else if (type == 3)
	{
		double* ptr = (double*)base;
		double temp = *ptr;;
		double temp2 = temp;
		for (int i = 1; i < exponent; ++i)
		{	
			temp = temp*temp2;
		}
		ptr = &temp;
		
		*(double*)base = *ptr;
		return;
	}else{
		printf("Wrong Type Parameter\n");
		return;				
	}


}