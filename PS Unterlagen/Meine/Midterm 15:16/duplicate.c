#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>  //isdigit()

#define LINE_MAX 2048

char* duplicate(char* str);
char* replicate(char* str, int times);
char* reverse(char* str);
int str_to_int(char* str);
char* userinput();

int main(int argc, char const **argv){
	
	char* str = duplicate("Hello");
	printf("%s\n",str);

	char* str2 = replicate("Hello",5);
	printf("%s\n",str2);

	char* str3 = reverse("World");
	printf("%s\n",str3);

	int int1 = str_to_int("1244");
	printf("%d\n",int1);

	char* userin = userinput();
	printf("%s\n",userin);

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
	printf("PLease input a string.\n");
	char* buffer = (char *)malloc(sizeof(char)*LINE_MAX);
	if (buffer == NULL){
		fprintf(stderr, "ERROR userinput - Allocation\n");
		exit(EXIT_FAILURE);
	}
	fgets(buffer, sizeof(char)*LINE_MAX, stdin);
	return buffer;
}
