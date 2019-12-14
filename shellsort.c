#include <stdio.h>
int main (){
    int a[] = {2,4,3,5,1,7,6,9,0,0}, n = 10;
    int i, j, g, key;
    for (g = n/2; g > 0; g /= 2){
        for (i = g; i < n; i++){
            key = a[i];
            for (j = i - g; j >= 0 && key > a[j]; j -= g){
                a[j+g] = a[j];
            }
            a[j+g] = key;
        }
    }
    for (i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}