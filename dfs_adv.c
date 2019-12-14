#include <stdio.h>
#include <stdlib.h>
#define END_X 3
#define END_Y 0
#define START_X 0
#define START_Y 0
#define LENGTH_A 4
#define LENGTH 3
#define MAX 99
int map[LENGTH_A][LENGTH_A] = {
	{1,1,0,0},
	{0,1,1,1},
	{1,1,0,1},
	{1,0,0,1}
};

int mark[4][4] = {
	{1,1,0,0},
	{0,1,1,1},
	{1,1,0,1},
	{1,0,0,1}
};
int move[4][2] = {
	{1,0},
	{-1,0},
	{0,1},
	{0,-1}
};

typedef struct node{
	int x;
	int y;
}n, *np;

typedef struct stack{
	np stk[MAX];
	int size;
}stack, *stack_ptr;

void stack_in(stack_ptr *stp, np new_node){
	(*stp)->stk[(*stp)->size++] = new_node;
	mark[new_node->x][new_node->y] = 0;
	printf("in: %d\n", (*stp)->size);
}

np stack_out(stack_ptr *stp){
	np last = (np)malloc(sizeof(n));

	last = (*stp)->stk[(*stp)->size-1];
	(*stp)->size--;
	printf("out: %d\n", (*stp)->size);
	return last;	
}

int main(void){
	stack_ptr stp  = (stack_ptr)malloc(sizeof(stack));
	stp->size = 0;
	int x = START_X, y = START_Y;
	np start = (np)malloc(sizeof(n));
	start->x = x;
	start->y = y;
	stack_in(&stp, start);
	while (stp->size != 0){
		np new_node = stack_out(&stp);
		for (int i = 0; i < 4; i ++){
			if(mark[new_node->x + move[i][0]][new_node->y + move[i][1]] == 1 && map[new_node->x + move[i][0]][new_node->y + move[i][1]] == 1 && new_node->x + move[i][0] >= 0 && new_node->x + move[i][0] < 4 && new_node->y + move[i][1] < 4 && new_node->y + move[i][0] >= 0){
				printf("x:%d  y:%d \n", new_node->x + move[i][0], new_node->y + move[i][1]);
				if (new_node->x + move[i][0] == END_X && new_node->y + move[i][1] == END_Y){
					printf("find out!\n");
					return 0;
				}
				np new = (np)malloc(sizeof(n));
				new->x = new_node->x + move[i][0];
				new->y = new_node->y + move[i][1];
				stack_in(&stp, new);
			}
		
		}
	}
	printf("no answer!\n");
	return 0;
}
