#include <stdio.h>

int main(void) {
	float a = 1.2;
	double x = sizeof(a) * 2 && 23 / printf("abc\n") ^ 4 + 1;  	// abc
	double y = ((int)a / 2 + (7 | 8) << 4); 
	double z = a * 6; 
	double u = 0xBADCAB1E ? 1 << 1 : 0xDEADC0DE; 
	double v = (u + z * 10) / 8;
	double w = (int)(u + z * 10) / 8;
 
	printf("x=%lf\n", x); 	//   0.000000
	printf("y=%lf\n", y); 	// 240.000000
	printf("z=%lf\n", z);  	//   7.200000
	printf("u=%lf\n", u); 	//   2.000000
	printf("v=%lf\n", v); 	//   9.250000
	printf("w=%lf\n", w);	//   9.000000
}


/* Antworten:





- true ,false

- true --> 		n > 0

- false --> 	n < 1

- Implizite Typecasts:

	- a: 1.2  --> 1		(double) --> (int)
	- w: senseless		 (int) 	 --> (int)









*/