#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int assign(int *a){
    char c;
    int i = 0;
    while (c != '\n'){
        if(scanf("%d", a+i) == 0){
            *(a+i) = 0;
        }
        i++;
        c = getchar();
    }
    return i;
}

int main()
{
    int *c = (int*)malloc(2500 * sizeof(int));
    int num = assign(c);
    for(int i = 0; i < num; i++){
        printf("%d\n", *(c+i));
    }
    return 0;
}