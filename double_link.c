#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct node{
	int data;
	struct node *pre;
	struct node *next;
}n, *np;

typedef struct link{
	int size;
	np first;
	np last;
}l, *lp;

np create_node(int num){
	np node = (np)malloc(sizeof(n));
	node->data = num;
	node->pre = NULL;
	node->next = NULL;
	return node;
}

lp create_link(int num){
	lp link = (lp)malloc(sizeof(l));
	link->size = 1;
	np node = create_node(num);
	link->first = node;
	link->last = node;
	return link;
}
/*
void insert_node(lp link, np node){
	(link)->size++;
	(link)->last = node;
	np temp = (link)->first;
	np temp1 = NULL;
	while (temp != NULL){
		temp1 = temp;
		temp = temp->next;
	}
	temp1->next = node;
	node->pre = temp1;
	
}*/

void insert_node(lp link, int num){
	np node = create_node(num);
	(link)->size++;
	(link)->last = node;
	np temp = (link)->first;
	np temp1 = NULL;
	while (temp != NULL){
		temp1 = temp;
		temp = temp->next;
	}
	temp1->next = node;
	node->pre = temp1;
	
}

void delete_node(lp link, int num){
	np node1 = link->first;
	np node2 = link->last;
	np temp1 = NULL, temp2 = NULL;
	while (node1->data != num){
		temp1 = node1;
		node1 = node1->next;
	}
	while (node2->data != num){
		temp2 = node2;
		node2 = node2->pre;
	}
	temp1->next = temp2;
	temp2->pre = temp1;
	free(node1);
	(link->size)--;
}

void print_link(lp link){
	np node = link->first;
	while (node != NULL){
		printf("%d -> ", node->data);
		node = node->next;
	}
}

void print_link2(lp link){
	np node = link->last;
	while (node != NULL){
		printf("%d -> ", node->data);
		node = node->pre;
	}
}

int main(void){
	lp link = create_link(0);
	print_link(link);
	putchar('\n');
	/*
	np node = create_node(1);
	insert_node(link, node);
	node = create_node(3);
	insert_node(link, node);
	node = create_node(2);
	insert_node(link, node);
	*/
	insert_node(link, 1);
	insert_node(link, 3);
	insert_node(link, 2);
	print_link(link);
	putchar('\n');
	printf("size: %d\n", link->size);
	printf("last: %d\n", link->last->data);
	print_link2(link);
	putchar('\n');
	delete_node(link, 3);
	print_link(link);
	putchar('\n');
	return 0;
}
