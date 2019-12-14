#include <stdio.h>
void swap(int a[], int i, int j){
	int temp;
	temp = a[i];
	a[i] = a[j];
	a[j] = temp; 
}

void print_list(int *a, int n){
	printf("List : ");	
	for (int i = 0; i < n; i++){
		printf("%d ", *(a+i));
	}
	putchar('\n');
}

void bubble_sort(int a[], int n){
	for (int i = 0; i < n-1; i++){
		for (int j = i+1; j < n; j++){
			if (a[i] > a[j]){
				swap(a, i, j);
			}
		}	
	}
}

void insert_sort(int a[], int n){
	int i, j, key;
	for (i = 1; i < n; i++){
		key = a[i];
		for (j = i-1; j >= 0 && key < a[j]; j--){
			a[j+1] = a[j];
		}
		a[j+1] = key;
	}
}

void select_sort(int a[], int n){
	int i, j, min;
	for (i = 0; i < n-1; i++){
		min = i;
		for (j = i+1; j < n; j++){
			if (a[j] < a[min]){
				min = j;
			}
		}
		if (i != min){
			swap(a, min, i);
		}
	}	
}

void shell_sort(int a[], int n){
	int i, j, key, g;
	for (g = n/2; g > 0; g/=2){
		for (i = g; i < n; i+=g){
			key = a[i];
			for (j = i-g; j >= 0 && a[j] > key; j-=g){
				a[j+g] = a[j];
			}
			a[j+g] = key;
			
		}
	} 
}
//merge_sort
void merge(int a[], int l, int m, int r){
	int left_size = m-l+1, right_size = r-m;
	int left[left_size], right[right_size];
	int i, j, k;
	for (i = l; i <= m; i++){
		left[i-l] = a[i];
	}
	for (j = m+1; j <= r; j++){
		right[j-m-1] = a[j];
	}
	i = 0, j = 0, k = l;
	while (i < left_size && j < right_size){
		if (left[i] < right[j]){
			a[k++] = left[i++];
		}
		else{
			a[k++] = right[j++];	
		}
	}
	while (i < left_size){
		a[k++] = left[i++];
	}
	while (j < right_size){
		a[k++] = right[j++];
	}
}

void split(int a[], int l, int r){
	if (l < r){
		int m = (l+r)/2;
		split(a, l, m);
		split(a, m+1, r);
		merge(a, l, m, r);
	}
}

void merge_sort(int a[], int n){
	split(a, 0, n-1);
}

//qucik_sort
int partition(int a[], int s, int e){
	int key = a[s];
	while (s < e){
		while (s < e && a[e] >= key){
			e--;
		}
		swap(a, s, e);
		while (s < e && a[s] <= key){
			s++;
		}
		swap(a, s, e);	
	}
	return s;
}

void qs(int a[], int s, int e){
	if (s < e){
		int p = partition(a, s, e);
		qs(a, s, p-1);
		qs(a, p+1, e);	
	}
}

void quick_sort(int a[], int num){
	qs(a, 0, num-1);
}
//heap_sort
void heapify(int a[], int s, int e){
	for(int i = 2*s; i <= e; i *= 2){
		if(i < e && a[i] > a[i+1]){
			i++;		
		}
		if(a[i] < a[i/2]){
			swap(a, i, i/2);
		}
	}
}

void heap_sort(int a[], int num){
	for (int i = num/2; i > 0; i--){
		heapify(a, i, num);
	}
	for (int i = num; i > 0; i--){
		swap(a, 1, i);
		heapify(a, 1, i-1);		
	}
}
int main(void){
	int a[] = {2,7,1,6,8,4,5,9,0,3}, n = 10;
	//int a[] = {-1,2,7,1,6,8,4,5,9,0,3}, n = 10;//heap_sort
	printf("Befor-------------------\n");	
	print_list(a, n);
	printf("After-------------------\n");
	//bubble_sort(a, n);
	//insert_sort(a, n);
	//select_sort(a, n);
	//shell_sort(a,n);
	//merge_sort(a, n);
	//quick_sort(a, n);
	//heap_sort(a, n);	
	print_list(a, n);	
	return 0;
}
