#include <stdio.h>
#include <stdlib.h>
#define MAX_V 7
#define MAX_E 12
#define START 1
#define END 5
typedef int vtype;

typedef struct edge_node{
	vtype x;
	vtype y;
}en, *ep;

typedef struct graph{
	int num_e;	
	int num_v;
	vtype map[MAX_V][MAX_V];

}g, *gp;

gp create_graph(){
	gp graph = (gp)malloc(sizeof(g));
	graph->num_e = 0;
	graph->num_v = MAX_V;
	for (int i = 0; i < MAX_V; i++){
		for (int j = 0; j < MAX_V; j++){
			graph->map[i][j] = -1;
		}
	}
	return graph;
}

ep create_edge(vtype x, vtype y){
	ep edge = (ep)malloc(sizeof(en));
	edge->x = x;
	edge->y = y;
	return edge;
}

void insert_edge(gp graph, ep edge){
	graph->num_e++;
	graph->map[edge->x][edge->y] = 1;
}

typedef struct queue{
	int size;
	int head;
	vtype v[100];
}q, *qp;

int step[MAX_V];
vtype pre[MAX_V];;

qp create_queue(vtype x){
	qp new = (qp)malloc(sizeof(q));
	new->size = 1;
	new->head = 0;
	for (int i = 0; i < MAX_V; i++){
		new->v[i] = 100;
	}
	new->v[0] = x;
	step[x] = 0;
	pre[x] = x;
	return new;
}

void queue_in(qp queue, vtype old, vtype new){
	queue->v[(queue->size)++] = new;
	step[new] = step[old] + 1;
	pre[new] = old;
	
}

vtype queue_out(qp queue){
	return queue->v[(queue->head)++];
}

int main(void){
	gp graph = create_graph();
	insert_edge(graph, create_edge(0, 1));
	insert_edge(graph, create_edge(0, 3));
	insert_edge(graph, create_edge(1, 3));
	insert_edge(graph, create_edge(1, 4));
	insert_edge(graph, create_edge(2, 0));
	insert_edge(graph, create_edge(2, 5));
	insert_edge(graph, create_edge(3, 2));
	insert_edge(graph, create_edge(3, 4));
	insert_edge(graph, create_edge(3, 5));
	insert_edge(graph, create_edge(3, 6));
	insert_edge(graph, create_edge(4, 6));
	insert_edge(graph, create_edge(6, 5));
	qp queue = create_queue(START);
	vtype old;
	int i;
	do{
		if (i == END){
			break;
		}
		old = queue_out(queue);
		for (i = 0; i < MAX_V; i++){
			if (graph->map[old][i] == 1){
				if (i == END){
					pre[i] = old;
					break;
				}
				queue_in(queue, old, i);				
				graph->map[old][i] = 2;
			}
		}
	}while(queue->size > 0);
	if (old != pre[END]){
		printf("no answer\n");
	}
	else{
		vtype temp = END;
		while (temp != pre[temp]){
			//printf("22222222222222222\n");
			printf("%d<-", temp);
			temp = pre[temp];
		}
		printf("%d\n", temp);
	}
	return 0;
}
