#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char a[] = "12345";
    printf("%p\n", a);
    printf("%s\n", &a[2]);

    return 0;
}