#include <stdio.h>
#include <stdlib.h>
#define MAX 999999

typedef int vtype; 

typedef struct Queue{
	int head;
	int tail;
	int size;
	vtype *list;
}queue, *queue_ptr;

typedef struct Node{
	vtype x, y;
	int weight;
}node, *node_ptr;

typedef struct Graph{
	int num_v, num_e;
	vtype **map;
}graph, *graph_ptr;

node_ptr create_edge(vtype x, vtype y, int weight){
	node_ptr new = (node_ptr)malloc(sizeof(node));
	new->x = x;
	new->y = y;
	new->weight = weight;
	return new;
}

graph_ptr create_graph(int size){
	graph_ptr new = (graph_ptr)malloc(sizeof(graph));
	new->num_v = size;
	new->num_e = 0;
	new->map = (vtype **)malloc(size * sizeof(vtype *));
	for (int i = 0; i < size; i++){
		new->map[i] = (vtype *)malloc(size * sizeof(vtype));
	}
	return new;	
}

void insert_edge(graph_ptr gp, node_ptr np){
	gp->num_e++;
	gp->map[np->x][np->y] = np->weight;
}

vtype* create_list(int size){
	vtype *list = (vtype *)malloc(sizeof(vtype) * size);
	return list;
}

int queue_empty(queue_ptr qp){
	if (qp->size == 0){
		return 1;
	}
	return 0;
}

void queue_push(queue_ptr qp, vtype new){
	qp->tail++;
	qp->list[qp->size++] = new;
}

vtype queue_pop(queue_ptr qp){
	qp->size--;
	return qp->list[qp->head++];
}

void init_array(vtype cost[], int size, int num){
	for (int i = 0; i < size; i++){
		cost[i] = num;
	}
}

queue_ptr create_queue(){
	queue_ptr qp = (queue_ptr)malloc(sizeof(queue));
	qp->size = 0;
 	qp->head = 0;
	qp->tail = -1;
	qp->list = create_list(MAX);
	return qp;	
}

void print_array(vtype a[], int size){
	for (int i = 0; i < size; i++){
		printf("%d ", a[i]);
	}
	putchar('\n');
}

int main(void){
	int size = 7;
	graph_ptr graph = create_graph(size);
	insert_edge(graph, create_edge(0, 1, 2));
	insert_edge(graph, create_edge(0, 3, 1));
	insert_edge(graph, create_edge(1, 3, 3));
	insert_edge(graph, create_edge(1, 4, 10));
	insert_edge(graph, create_edge(2, 0, 4));
	insert_edge(graph, create_edge(2, 5, 5));
	insert_edge(graph, create_edge(3, 2, 2));
	insert_edge(graph, create_edge(3, 4, 7));
	insert_edge(graph, create_edge(3, 5, 8));
	insert_edge(graph, create_edge(3, 6, 4));
	insert_edge(graph, create_edge(4, 6, 6));
	insert_edge(graph, create_edge(6, 5, 1));
	vtype start = 0;
	vtype cost[size], pre[size];
	init_array(cost, size, MAX);
	init_array(pre, size, -1);
	cost[start] = 0;
	pre[start] = 0;
	
	queue_ptr qp = create_queue();
	queue_push(qp, start);
	//printf("%d\n", qp->size);
	while (!queue_empty(qp)){
		vtype new = queue_pop(qp);
		//printf("111111111  %d  1111111\n", new);
		for (vtype i = 0; i < size; i++){
			//printf("%d %d\n", cost[new], graph->map[new][i]);
			if (cost[i] > cost[new] + graph->map[new][i] && graph->map[new][i] != 0){
				cost[i] = cost[new] + graph->map[new][i];
				pre[i] = new;
				//printf("%d\n", i);
				queue_push(qp, i);
			}
		}
	}
	print_array(cost, size);
	print_array(pre, size);
	for (vtype j = 0; j < size; j++){
		vtype i = j;
		if (i != start){
			while (i != 0){
				printf("%d -> ", i);
				i = pre[i];
			}
			putchar('\n');
		}
	}
	return 0;
}
