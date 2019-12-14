#include <stdio.h>
void swap(int a[], int i, int j){
	int temp;
	temp = a[i];
	a[i] = a[j];
	a[j] = temp; 
}

void show_list(int a[], int num){
	for (int i = 0; i < num; i++){
		printf("%d ", a[i]);
	}
	putchar('\n');
}


void heapify(int a[], int s, int e){// s means start, e means end
	for (int i = 2*s; i <= e; i *= 2){
		if (i < e && a[i] > a[i+1]){
			i++;
		}
		if (a[i] < a[i/2]){
			swap(a, i, i/2);
		}
	}
}


void heap_sort(int a[], int num){
	for (int i = num/2; i > 0; i--){
		heapify(a, i, num-1);
	}
	for (int i = num-1; i > 0; i--){
		swap(a, 1, i);
		heapify(a, 1, i-1);		
	}
}

int main(void){
	int size = 10;
	int a[] = {0,1,3,5,7,9,2,4,6,8};
	heap_sort(a, size);
	show_list(a, size);
	return 0;
}
