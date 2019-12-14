#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode{
	int data;
	struct TreeNode *lc, *rc;
}tn, *tp;


void make_tree(tp *node){
	int num;
	scanf("%d", &num);
	getchar();
	if (num == -1){
		*node = NULL;
	}
	else{
		*node = (tp)malloc(sizeof(tn));
		(*node)->data = num;
		printf("please %d's left son: ", num);
		make_tree(&(*node)->lc);
		printf("please %d's right son: ", num);
		make_tree(&(*node)->rc);		
	}

}

void preorder(tp head){
	if (head != NULL){
		printf("%d ", head->data);
		preorder(head->lc);
		preorder(head->rc);
	}
}

int main(void){
	tp tree = NULL;
	printf("please enter the node(end with -1): ");
	make_tree(&tree);
	preorder(tree);
	return 0;
}
