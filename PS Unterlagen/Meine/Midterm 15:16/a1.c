#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//Prototypes
bool isleapyear(int year);

//Main
int main(int argc, char const **argv){
	
	int firstyear = 1582;
	int lastyear = 2400;

	for (int i = firstyear; i < lastyear+1; i++){
		if(isleapyear(i)){
			printf("Year %d: yes\n",i);
		}else{
			printf("Year %d:  no\n",i);
		}
	}

	return EXIT_SUCCESS;
}

//Functions
bool isleapyear(int year){
	if (year % 400 == 0){		//Ausnahme zu Regel 2
		return true;
	}else if (year % 100 == 0){ //Ausnahme zu Regel 1
		return false;
	}else if (year % 4 == 0){	//Regel 1
		return true;
	}
	return false;
}