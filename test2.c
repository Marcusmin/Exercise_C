#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
	int data;
	struct TreeNode *lc, *rc;
	
}tn, *tp;

void insert_tree(tp *node, int num){
	tp new_node = (tp)malloc(sizeof(tn));
	new_node->data = num;
	new_node->lc = NULL;
	new_node->rc = NULL;
	if (*node == NULL){
		*node = new_node;
		return;
	}
	else{
		tp temp = *node;
		while (temp != NULL){
			if (num > temp->data){
				if(temp->rc == NULL){
					temp->rc = new_node;
					return;
				}
				else{
					temp = temp->rc;				
				}
			}
			else{
				if(temp->lc == NULL){
					temp->lc = new_node;
					return;
				}
				else{
					temp = temp->lc;				
				}
			}
		}
	}
		
}

void preorder(tp node){
	if (node != NULL){
		printf("%d ", node->data);
		preorder(node->lc);
		preorder(node->rc);
	}
}

int main(void){
	int a[] = {2,6,4,1,3,9,8,0,5,7};
	tp head = NULL;
	for (int i = 0; i < 10; i++){
		insert_tree(&head, a[i]);	
	}
	preorder(head);
	return 0;
}
