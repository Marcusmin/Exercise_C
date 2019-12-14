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
	if ((*node) == NULL){
		*node = new_node;
	}
	else{
		tp temp = *node;//保留树头
		while (temp != NULL){
			if (num > (temp->data)){
				if (temp->rc == NULL){
					temp->rc = new_node;
					return;
				}
				else{
					temp = temp->rc;
				}
			}
			else{
				if (temp->lc == NULL){
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


void del_tree(tp *node, int num){
	tp t1 = *node;
	tp t2 = NULL;
	while (t1 != NULL){
		if (num == t1->data){
			if (t1->lc == NULL && t1->rc ==NULL){
				if (t2->lc == t1){
					t2->lc = NULL;
				}
				else{
					t2->rc = NULL;
				}
				free(t1);
				printf("%d has been moved!\n", num);
				return;
								
			}
			else if (t1->lc == NULL){
				tp temp = t1->rc;
				if (t2->lc == t1){
					t2->lc = temp;
				}
				else{
					t2->rc = temp;
				}
				free(t1);
				printf("%d has been moved!\n", num);
				return;
			}
			else if (t1->rc == NULL){
				tp temp = t1->lc;
				if (t2->lc == t1){
					t2->lc = temp;
				}
				else{
					t2->rc = temp;
				}
				free(t1);
				printf("%d has been moved!\n", num);
				return;
			}
			else{//直接前驱，转左后右尽头 中序遍历
				tp target = t1->lc;
				tp before = NULL;
				while (target->rc != NULL){
					before = target;
					target = target->rc;
					
				}
				if (before != NULL){//避免根头
					before->rc = target->lc;
				}
				if (t2 != NULL && t2->lc == t1){
					t2->lc = target;
				}
				else if (t2 != NULL && t2->rc == t1){
					t2->rc = target;
				}
				else{
					*node = target;
				}
				if (t1->lc != target){//避免转左后无右
					target->lc = t1->lc;
				}
				target->rc = t1->rc;
				free(t1);
				printf("%d has been moved!\n", num);
				return;

			}
		}
		else if (num > t1->data){
			t2 = t1;
			t1 = t1->rc;
		}
		else{
			t2 = t1;
			t1 = t1->lc;
		}
	}
	printf("number: %d doesn't exist!!!\n", num);
 }



void preorder(tp node){
	if (node == NULL){
		return;
	}
	printf("%d\n", node->data);
	preorder(node->lc);
	preorder(node->rc);
}

int main(void){
	tp top = NULL;
	int a[] = {6,1,2,5,8,9,7,3,4,0};
	for (int i = 0; i<10; i++){
		insert_tree(&top, a[i]);
	}
	del_tree(&top, 8);
	preorder(top);
	return 0;
}
