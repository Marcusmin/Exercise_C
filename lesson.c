#include<stdio.h>
#include<stdlib.h>

int main(void){
  char *b = "hello";
  char *a = b;
  a = "111";
  a = (++b);
  printf("%s\n",a );
  //printf("%c\n",a+2);
}