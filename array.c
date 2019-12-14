#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void){
    char *a = (char *)malloc(10000*sizeof(char));
    printf("please enter\n");
    scanf("%s", a);
    char *p = " ";
    printf("%s\n", strtok(a, p));
    /*int temp;
    char c = '9';
    temp = atoi(&c);
    printf("%d\n", temp);

    char *s = "123";
    temp = atoi(s);
    printf("%d\n", temp);*/
    
    return 0;
}