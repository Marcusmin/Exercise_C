#include <stdio.h>
#include <math.h>
int fabi(int num){
	if (num == 0){
		return 0;
	}
	else if (num == 1){
		return 1;
	}
	int a = fabi(num-1)+fabi(num-2);
	return a;
	
} 

void fabi_b(int num){
	int f1 = 0, f2 = 1;
	for (int i = 0; i < num; i++){
		printf("%d %d ", f1, f2);
		f1 = f1 + f2;
		f2 = f1 + f2;
	}
}

/*void prime(int n1, int n2){
	int s1, s2, i, j;
	s1 = sqrt(n1+1); 
	for (i = n1; i <= n2; i++){
		s2 = sqrt(i+1);
		for (j = 2; j <= s2; j++){
			if (i % j == 0){
				break;			
			}
		}
		if (j-1 == s2){
			printf("%d ", i);
		}
	}
}*/

void flower(int n1, int n2){
	for (int i = n1; i <= n2; i++){
		int g, s, b;
		g = i % 10;
		s = (i / 10) % 10;
		b = (i / 100) % 10;
		if (g*g*g + s*s*s + b*b*b == i){
			printf("%d ", i);
		}
	}
}

void div(int num){
	printf("%d = ", num);
	int i, temp = num;
	for (i = 2; i < temp; i++){
		if (num % i == 0 && num != i){
			num /= i;
			printf("%d* ", i);
			i--;
		}
		if (num == i){
			printf("%d\n", i);
		}
	}

}

int main(void){
	//fabi_b(5);
	//prime(101, 200);
	//flower(100, 999);
	//div(5005);
	return 0;
}
