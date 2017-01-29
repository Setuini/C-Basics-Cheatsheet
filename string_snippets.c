#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>  //isdigit()

#define LINE_MAX 2048

char* duplicate(char* str);
char* replicate(char* str, int times);
char* reverse(char* str);
void duplicate_ptr(char** strptr);
void replicate_ptr(char** strptr, int times);
void reverse_ptr(char** strptr);
int str_to_int(char* str);
char* userinput();

int main(int argc, char const **argv){
	
	char test[] = "Hello";
	char test2[] = "1234";

	//Functions with return
	char* str = duplicate(test);
	printf("Duplicate:           %s\n",str);
	free(str);

	char* str2 = replicate(test,5);
	printf("Replicate:           %s\n",str2);
	free(str2);

	char* str3 = reverse(test);
	printf("Reverse:             %s\n\n",str3);
	free(str3);

	//Functions with pointer passing
	char* str4 = test;
	char** strptr = &str4;

	duplicate_ptr(strptr);
	printf("Duplicate Pointer:   %s\n",*strptr);

	*strptr = "Hello"; //reset the string to Hello
	replicate_ptr(strptr, 5);
	printf("Replicate Pointer:   %s\n",*strptr);

	*strptr = "Hello"; //reset the string to Hello
	reverse_ptr(strptr);
	printf("Reverse Pointer:     %s\n\n",*strptr);

	free(*strptr);

	//String to int
	int int1 = str_to_int(test2);
	printf("String to int:       %d\n\n",int1);

	//Userinput
	char* userin = userinput();
	printf("User Input:          %s\n\n",userin);
	free(userin);
	
	return EXIT_SUCCESS;
}

//Duplicates a String - Example: "Hello\0" -> "HelloHello\0"
char* duplicate(char* str){
	int len = strlen(str);
	char* retval = (char *)malloc( (sizeof(char) * len * 2) + 1); // +1 for \0
	if (retval == NULL){
		fprintf(stderr, "ERROR duplicate - Allocation\n");
		exit(EXIT_FAILURE);
	}
	strcpy(retval, str);
	strcat(retval, str);
	retval[len*2] = '\0';
	return retval;
}

//Replicates a String - Example: "Hello\0" 4 -> "HelloHelloHelloHello\0"
char* replicate(char* str, int times){
	int len = strlen(str);
	char* retval = (char *)malloc( (sizeof(char) * len * times) + 1); // +1 for \0
	if (retval == NULL){
		fprintf(stderr, "ERROR replicate - Allocation\n");
		exit(EXIT_FAILURE);
	}
	strcpy(retval, str);
	for (int i = 0; i < times; i++){
		strcat(retval, str);
	}
	retval[len*times] = '\0';
	return retval;
}

//Reverses a String - Example "Hello\0" -> "olleH\0"
char* reverse(char* str){
	int len = strlen(str);
	char* retval = (char *)malloc((sizeof(char) * len) + 1);
	int j = len-1;
	for (int i = 0; i < len; i++){
		retval[j--] = str[i];
	}
	return retval;
}

void duplicate_ptr(char** strptr){
	int len = strlen(*strptr);
	char* new = (char *)malloc( (sizeof(char) * len * 2) + 1); // +1 for \0
	if (new == NULL){
		fprintf(stderr, "ERROR duplicate - Allocation\n");
		exit(EXIT_FAILURE);
	}
	strcpy(new, *strptr);
	strcat(new, *strptr);
	new[len*2] = '\0';
	*strptr = new;
}

void replicate_ptr(char** strptr, int times){
	int len = strlen(*strptr);
	char* new = (char *)malloc( (sizeof(char) * len * times) + 1); // +1 for \0
	if (new == NULL){
		fprintf(stderr, "ERROR duplicate - Allocation\n");
		exit(EXIT_FAILURE);
	}
	strcpy(new, *strptr);
	for (int i = 0; i < times; i++){
		strcat(new, *strptr);
	}
	new[len*times] = '\0';
	*strptr = new;
}

void reverse_ptr(char** strptr){
	int len = strlen(*strptr);
	char* new = (char *)malloc( (sizeof(char) * len) + 1); // +1 for \0
	if (new == NULL){
		fprintf(stderr, "ERROR duplicate - Allocation\n");
		exit(EXIT_FAILURE);
	}
	int j = len-1;
	for (int i = 0; i < len; i++){
		new[j--] = (*strptr)[i];
	}
	new[len] = '\0';
	*strptr = new;
}

//Parses a int from a string - Example "100" -> 100
int str_to_int(char* str){
	char* end;
	int base = 10;
	for (int i = 0; i < strlen(str); i++){
		if (!isdigit(str[i])){
			fprintf(stderr, "ERROR str_to_int - string contains non digit\n");
			return 0;
		}
	}
	int retval = strtol(str,&end,base);
	if(end == str){
		fprintf(stderr, "ERROR str_to_int\n");
		return 0;
	}
	return retval;
}

//Get input from stdin
char* userinput(){
	printf("Please input a string.\n");
	char* buffer = (char *)malloc(sizeof(char)*LINE_MAX);
	if (buffer == NULL){
		fprintf(stderr, "ERROR userinput - Allocation\n");
		exit(EXIT_FAILURE);
	}
	fgets(buffer, sizeof(char)*LINE_MAX, stdin);
	return buffer;
}