#include <stdio.h>
#include <stdlib.h>

#define MAX 100001
//for edge
typedef int vtype;

typedef struct Edge{
	vtype x, y;
	int weight;
}edge, *edge_ptr;


typedef struct Graph{
	vtype **map;
	int num_e, num_v;
}graph, *graph_ptr;

graph_ptr create_graph(int size){
	graph_ptr graph = (graph_ptr)malloc(sizeof(graph));
	graph->map = (vtype **)malloc(size * sizeof(vtype*));
	for (int i = 0; i < size; i++){
		graph->map[i] = (vtype *)malloc(size * sizeof(vtype));
	}
	graph->num_e = 0;
	graph->num_v = size;
	return graph;
}

edge_ptr create_edge(vtype x, vtype y, int weight){
	edge_ptr edge = (edge_ptr)malloc(sizeof(edge));
	edge->x = x;
	edge->y = y;
	edge->weight = weight;
	return edge;
}

void insert_edge(graph_ptr graph, edge_ptr edge, edge_ptr list[]){
	list[graph->num_e] = edge;
	graph->num_e++;
	graph->map[edge->x][edge->y] = edge->weight;
}

void bellman_ford(int size, int start, graph_ptr graph, edge_ptr list[]){
	int cost[size], pre[size];
	for (int i = 0; i < size; i++){
		pre[i] = -1;
		cost[i] = MAX;
	}
	cost[start] = 0;
	for (int i = 0; i < size-1; i++){
		for (int j = 0; j < graph->num_e; j++){
			if (cost[list[j]->x] + list[j]->weight < cost[list[j]->y]){
				cost[list[j]->y] = cost[list[j]->x] + list[j]->weight;
				pre[list[j]->y] = list[j]->x;
			}
		}
	}
	for (int i = 0; i < size; i++){
		int temp = i;
		if (temp != start){
			while (temp != start && pre[temp] != -1){
				printf("%d -> ", temp);
				temp = pre[temp];	
			}
			printf("%d\n", start);
		}
	}
	printf("cost\n");
	for (int i = 0; i < size; i++){
		printf("%d ", cost[i]);
	}
	putchar('\n');
	printf("pre\n");
	for (int i = 0; i < size; i++){
		printf("%d ", pre[i]);
	}
	putchar('\n');
}

int main(void){
	int size = 7;
	graph_ptr graph = create_graph(size);
	edge_ptr list[20];
	list[20] = (edge_ptr)malloc(sizeof(edge)*20);
	insert_edge(graph, create_edge(0, 1, 2), list);
	insert_edge(graph, create_edge(0, 3, 1), list);
	insert_edge(graph, create_edge(1, 3, 3), list);
	insert_edge(graph, create_edge(1, 4, 10), list);
	insert_edge(graph, create_edge(2, 0, 4), list);
	insert_edge(graph, create_edge(2, 5, 5), list);
	insert_edge(graph, create_edge(3, 2, 2), list);
	insert_edge(graph, create_edge(3, 4, 7), list);
	insert_edge(graph, create_edge(3, 5, 8), list);
	insert_edge(graph, create_edge(3, 6, 4), list);
	insert_edge(graph, create_edge(4, 6, 6), list);
	insert_edge(graph, create_edge(6, 5, 1), list);
	for (int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			printf("%2d ", graph->map[i][j]);
		}
		putchar('\n');
	}
	printf("%d\n", size);
	bellman_ford(size, 0, graph, list);

	
	
	return 0;
}
