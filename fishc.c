#include <stdio.h>
void merge(int a[], int l, int m, int r){
    int left_size = m-l+1, right_size = r-m;
    int left[left_size], right[right_size];
    int i, j, k;
    for (i = l; i <= m; i++){
        left[i-l] = a[i];
    }
    for (i = m+1; i <= r; i++){
        right[i-m-1] = a[i];
    }
    i = 0, j = 0, k = l;
    while (i<left_size && j<right_size){
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

void mergesort(int a[], int l, int r){
    if (l < r){
        int m = (l+r)/2;
        mergesort(a, l, m);
        mergesort(a, m+1, r);
        merge(a, l, m, r);
    }
}

int main(){
    int a[] = {6,73,18,9,1444,2,2313,4};
    int l = 0, r= 7, m = (l +r)/2;//m=3
    //merge(a, l, m, r);
    mergesort(a, l, r);
    for (int i = 0; i <= r; i++){
        printf("%d ", a[i]);
    }
    return 0;
}
