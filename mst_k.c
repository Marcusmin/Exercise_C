#include <stdio.h>
#include <stdlib.h>
#define MAX 12
#define NODE_N 7
#define MIN 100
typedef int vtype;

typedef struct MAP{
	int nv;//number of vertexes
	int ne;//number of edges
	vtype v[MAX][MAX];//array -> weight & edge
}map, *map_ptr; 

typedef struct ENode{//for each edge
	vtype i, j;
	int weight;	
}en, *enp;

map_ptr create_map(int num){//create a map without any edges
	vtype i, j;
	map_ptr mst = (map_ptr)malloc(sizeof(map));
	mst->nv = num;
	mst->ne = 0;
	for (i = 0; i < mst->nv; i++){
		for (j = 0; j < mst->nv; j++){
			mst->v[i][j] = 0;//initialize all edge as 0
		}
	}
	return mst;
}

void insert_edge(map_ptr mst, enp enode){
	(mst->ne)++;
	mst->v[enode->i][enode->j] = enode->weight;
	mst->v[enode->j][enode->i] = enode->weight;
}

enp create_node(vtype i, vtype j, int weight){
	enp node = (enp)malloc(sizeof(en));
	node->i = i;
	node->j = j;
	node->weight = weight;
	return node;
}

int in_list(vtype a[], vtype n){//check whether is a ring
	for (int i = 0; i < NODE_N; i++){
		if (a[i] == n){
			return 1;		
		}
	}
	return 0;
}

void insert(vtype b[], int *num, enp node){
	vtype x = node->i;
	vtype y = node->j;
	if (!in_list(b, x)){
		b[(*num)++] = x;
	}
	if (!in_list(b, y)){
		b[(*num)++] = y;
	}
}

void swap(enp a[], int i, int j){
	enp temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void select_sort(enp a[], int num){
	int i, j, min;
	for (i = 0; i < num; i++){
		min = i;
		for (j = i+1; j < num; j++){
			if (a[j]->weight < a[min]->weight){
				min = j;
			}
		}
		swap(a, i, min);
	}
}
int f[100];

int find_f(int num){
	while (num != f[num]){
		num = f[num];
	}
	return num;
}

void join(int x, int y){
	int fx = find_f(x);
	int fy = find_f(y);
	if (fx != fy){
		f[fy] = fx;
	}
}
int main(void){
	map_ptr mst = (map_ptr)malloc(sizeof(map));
	mst = create_map(NODE_N);
	enp node[MAX];
	int i;
	for (i = 0; i < MAX; i++){
		node[i] = NULL;
	}
	node[0] = create_node(0, 1, 2);
	node[1] = create_node(0, 2, 4);
	node[2] = create_node(0, 3, 1);
	node[3] = create_node(1, 3, 3);
	node[4] = create_node(1, 4, 10);
	node[5] = create_node(2, 3, 2);
	node[6] = create_node(2, 5, 5);
	node[7] = create_node(3, 4, 7);
	node[8] = create_node(3, 5, 8);
	node[9] = create_node(3, 6, 4);
	node[10] = create_node(4, 6, 6);
	node[11] = create_node(5, 6, 1);
	for (i = 0; i < MAX; i++){
		insert_edge(mst, node[i]);
	}
	select_sort(node, MAX);
	for (i = 0; i < NODE_N; i++){
		f[i] = i;
	}
	int edge_num = 0, sum = 0;
	for (i = 0; i < MAX && edge_num < NODE_N-1; i++){
		if (find_f(node[i]->j) != find_f(node[i]->i)){
			join(node[i]->i, node[i]->j);
			printf("(%d, %d) ", node[i]->j, node[i]->i);
			sum += node[i]->weight;
			edge_num++;
		}
	}
	putchar('\n');
	printf("sum: %d\n", sum);
	return 0;
}
















