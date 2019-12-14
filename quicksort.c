#include <stdio.h>
void swap(int a[], int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int partition(int a[], int s, int e){
    int point = a[s];
    while (s < e){
        while (s < e && a[e] >= point){
            e--;
        }
        swap(a, s, e);
        while (s < e && a[s] <= point){
            s++;
        }
        swap(a, s, e);
    }
    return s;
}

void Qsort(int a[], int s, int e){
    if (s < e){
        int p = partition(a, s, e);
        Qsort(a, s, p-1);
        Qsort(a, p+1, e);
    }
}

void quicksort(int a[], int n){
    Qsort(a, 0, n-1);
}


int main(){
    int a[] = {4,6,8,9,7,2,2,1,0,5};
    quicksort(a, 10);
    for (int i = 0; i<10; i++){
        printf("%d ", a[i]);
    }
    return 0;
}