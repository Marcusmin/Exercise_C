#include <stdio.h>
#define PRICE 21
int money[] = {1,5,10};

int dp(int a[], int num){
	int rest, i, j = 0, min = num;
	if (num < 5){
		for (i = 0; i < 5; i++){
			a[i] = i;
		}
		return a[num];
	}
	else{
		for (j = 0; j < 3; j++){
			if (money[j] > num){
				break;
			}
			rest = num - money[j];
			int temp = dp(a, rest);
			if (temp < min){
				min = temp;
			}	
		}
		a[num] = min+1;
		return a[num];
		
	}
}

void print(int a[], int num){
	for (int i = 1; i < num; i++){
		printf("%d needs %d coins\n", i, a[i]);
	}
}

int main(void){
	int a[PRICE];
	dp(a, PRICE);
	print(a, PRICE);
	return 0;
}
