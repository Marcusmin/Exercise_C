#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ELEMENTTYPE int
typedef struct linknode{
	ELEMENTTYPE data;
	struct linknode *next;	
}ln, *lp;

lp make_link(int num){
	lp head = (lp)malloc(sizeof(ln));
	lp node = (lp)malloc(sizeof(ln));
	memset(node, 0, sizeof(ln));
	node->data = num;
	head->next = node;
	return head;

}

void head_insert(lp head, int num){
	lp new_node = (lp)malloc(sizeof(ln));
	new_node->next = head->next;
	head->next = new_node;
	new_node->data = num;
	
}

void tail_insert(lp head, int num){
	lp new_node = (lp)malloc(sizeof(ln));
	memset(new_node, 0, sizeof(ln));
	new_node->data = num;
	lp node = head;
	while (node->next != NULL){
		node = node->next;	
	}
	node->next = new_node;
}

void del(lp head, int num){
	lp p1 = NULL, p2 = NULL;
	p1 = head->next;
	while (p1 != NULL && p1->data != num){
		p2 = p1;		
		p1 = p1->next;
	}
	if (p1->data == num){
		if (p1 == head->next){
			head->next = p1->next;		
		}
		else{
			p2->next = p1->next;
		}
		free(p1);
		printf("%d has been removed.\n", num);
	}
	else{
		printf("number hasn't been found.\n");
	}

}

int print_link(lp head){
	if (head->next == NULL){
		putchar('\n');
		return 0;
	}
	printf("%d ", head->next->data);
	
	print_link(head->next);

}

int main(void){
	int n = 100;
	lp head = make_link(n);
	head_insert(head, 3);
	head_insert(head, 2);
	head_insert(head, 1);
	tail_insert(head, 9);
	tail_insert(head, 99);
	print_link(head);
	del(head, 99);	
	print_link(head);		
	return 0;
}

