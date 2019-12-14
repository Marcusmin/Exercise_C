#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverse(char* s){
	
	int size = strlen(s);
	char str[size];
	strcpy(str, s);
	int i;
	char temp;
	//printf("111111111111\n");
	//printf("%d\n", size);
	for (i = size-1; i >= size/2; i--){
		temp = *(s + i);
		//printf("temp: %c, i: %d, size/2: %d\n", *(str + size  - i - 1), i, size/2);
		*(str + i) = *(str + size  - i - 1);
		//printf("c1:%c c2:%c\n", *(str + i), *(str + size  - i - 1));
		*(str + size  - i -1) = temp;
	}
	printf("string : %s\n", str);
	char *temp1 = str;
	strcpy(temp1, str);
	printf("string : %s\n", temp1);
	return temp1;
}
/*
int get_next(char *str){
	int size = strlen(str);
	int next[size], i, j;
	next[0] = -1;
	for (i = 1; i < size-1; i++){
		if (strcmp(str+i, ))
	}
	next[size-1] = 0;	
	
}*/

int main(void){
	char *str = "aaaab";//-1 1 2 2 0
	char* s1 = reverse(str);
	int n;
	printf("%s\n", str);
	//printf("%c, %s\n", *(str+1), test);
	return 0;
}

