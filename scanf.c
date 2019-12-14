#include <stdio.h>

int main(void){
	int sum = 0, a = 0;	
	while (1){
		int flag = scanf("%d", &a);
		
		if (flag == 0){
			getchar();
			continue;
		}
		else if (flag > 0){
			sum += a;
			printf("a: %d\n", a);
			printf("sum: %d\n", sum);
			continue;		
		}
		else {
			break;	
		}
		
	}
	printf("%d", sum);
	return 0;
}
