#include <stdio.h>
#define NUM -1


int valid(int a[], int num, int i){
	if (i == 0){
		return (a[i] == num);
	}
	else if (a[i] > num){
		return valid(a, num, i-1);
	}
	else if (num == 0){
		return 1;
	}
	else{
		return (valid(a, num, i-1) || valid(a, num-a[i], i-1));
	}
	
}
int shell(int a[], int num){
	return valid(a, num, 8);
}
int main(void){
	int a[] = {1,2,3,4,5,6,7,8,9};
	int flag = shell(a, NUM);
	if (flag){
		printf("yes\n");
	}
	else{
		printf("No!\n");
	}
	return 0;
}
