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
	int weight;
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

ep create_edge(vtype x, vtype y, int w){
	ep edge = (ep)malloc(sizeof(en));
	edge->x = x;
	edge->y = y;
	edge->weight = w;
	return edge;
}

void insert_edge(gp graph, ep edge){
	graph->num_e++;
	graph->map[edge->x][edge->y] = edge->weight;
}

int cost[MAX_V], visited[MAX_V];
vtype pre[MAX_V];

typedef struct list{
	vtype l[MAX_V];
	int size;
}l, *lp;

int valid(int a[], int num){
	for (int i = 0; i < num; i++){
		if (a[i] == -1){
			return 0;
		}
	}
	return 1;
}

int in(int a[], int x){
	for (int i = 0; i < MAX_V; i++){
		if (a[i] == x){
			return 1;			
		}
	}
	return 0;
}

void print(int a[]){
	printf(": ");
	for (int i = 0; i < 7; i ++){
		printf("%d ", a[i]);
	}
	putchar('\n');
}

int main(void){
	gp graph = create_graph();
	insert_edge(graph, create_edge(0, 1, 2));
	insert_edge(graph, create_edge(0, 3, 1));
	insert_edge(graph, create_edge(1, 3, 3));
	insert_edge(graph, create_edge(1, 4, 10));
	insert_edge(graph, create_edge(2, 0, 4));
	insert_edge(graph, create_edge(2, 5, 5));
	insert_edge(graph, create_edge(3, 2, 2));
	insert_edge(graph, create_edge(3, 4, 2));
	insert_edge(graph, create_edge(3, 5, 8));
	insert_edge(graph, create_edge(3, 6, 4));
	insert_edge(graph, create_edge(4, 6, 6));
	insert_edge(graph, create_edge(6, 5, 1));
	int i, j;
	lp list = (lp)malloc(sizeof(l));
	for (i = 0; i < MAX_V; i++){
		list->l[i] = -1;
		cost[i] = 9999;
	}
	list->size = 0;
	cost[0] = 0;
	cost[1] = 2;
	cost[3] = 1;
	pre[1] = 1;
	pre[3] = 1;
	visited[0] = 1;
	list->l[0] = 0;
	while (1){
		if (valid(list->l, MAX_V)){
			break;
		}
		int min = 555;
		vtype temp_x = -1, temp_y = -1;
		for (i = 0; i < MAX_V; i++){
			if (in(list->l, i)){
				for (j = 0; j < MAX_V; j++){
					if (cost[i] < min && graph->map[i][j] != -1 ){
						if (visited[j] != 1){	
							min = graph->map[i][j];
							temp_x = j;
						}
					}
				}
			}
		}
		if (temp_x != -1){
			printf("temp_x: %d\n", temp_x);
			visited[temp_x] = 1;
			list->l[++(list->size)] = temp_x;
			for (j = 0; j < MAX_V; j++){
				if (visited[j] != 1 && graph->map[temp_x][j] != -1){
					//printf("j: %d\n", j);
					if (cost[temp_x] + graph->map[temp_x][j] < cost[j]){
						cost[j] = cost[temp_x] + graph->map[temp_x][j];
						pre[j] = temp_x;
					}	
				}
			}
		}
	}
	printf("cost");
	print(cost);
	printf("pre");
	print(pre);
	return 0;
}
