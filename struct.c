#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
}N, *Np;

int main(void){
    int a[] = {1,2,3,4,5,6,7,8,9,0};
    Np p = (Np)malloc(sizeof(N) * 10);
    for (int i = 0; i < 10; i++){
            (p+i)->data = a[i];
    }
    for (int i = 0; i < 10; i++){
            printf("%d\n", (p+i)->data);
    }

    return 0;
}