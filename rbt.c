#include <stdio.h>
#include <stdlib.h>

#define ctype int
#define RED 1
#define BLACK 0

typedef struct node{
	int data;
	ctype color;
	struct node* lc;
	struct node* rc;
	struct node* p;
}node, *node_ptr;

typedef struct br_tree{
	node_ptr root;
}tree, *tree_ptr;

node_ptr create_node(int data){
	node_ptr node = (node_ptr)malloc(sizeof(struct node));
	node->data = data;
	node->color = RED;
	node->lc = NULL;
	node->rc = NULL;
	node->p = NULL;
	return node;
}

void insert(tree_ptr tree, node_ptr node){
	/*if (tree->root == NULL){
		tree->root = node;
		return;
	}
	node_ptr* temp = &(tree->root);
	while ((*temp) != NULL){
		if (node->data > (*temp)->data){
			temp = &((*temp)->rc);
		}
		else{
			temp = &((*temp)->lc);
		}	
	}
	(*temp) = node;*/
	if (tree->root == NULL){
		tree->root = node;
		return;
	}
	node_ptr temp = tree->root;
	while (temp != NULL){
		if (node->data > temp->data){
			if (temp->rc == NULL){
				node->p = temp;
				temp->rc = node;
				return;
			}
			temp = temp->rc;
		}
		else{
			if (temp->lc == NULL){
				node->p = temp;
				temp->lc = node;
				return;
			}
			temp = temp->lc;
		}
	}
}

void fix_up(tree_ptr tree, node_ptr node){
	if (tree->root->color != BLACK){
		tree->root->color = BLACK;
	}
	
}

int main(void){
	tree_ptr tree = (tree_ptr)malloc(sizeof(tree));
	tree->root = NULL;
	node_ptr node = create_node(5);
	insert(tree, node);
	node = create_node(6);
	insert(tree, node);
	node = create_node(4);
	insert(tree, node);
	printf("%d\n", node->p->data);
	return 0;
}
