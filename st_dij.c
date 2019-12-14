#include <stdio.h>
#include <stdlib.h>
#define MAX_V 7
#define MAX_E 12
#define MAX_D 9999
//for point
typedef int vtype;

typedef struct edge_node{
	int weight;
	vtype x, y;
}en, *enp;

typedef struct graph{
	vtype map[MAX_V][MAX_V];
	int num_v;
	int num_e;
}g, *gp;

gp create_graph(){
	gp graph = (gp)malloc(sizeof(g));
	graph->num_v = MAX_V;
	graph->num_e = 0;
	for(int i = 0; i < MAX_V; i++){
		for (int j = 0; j < MAX_V; j++)
			graph->map[i][j] = MAX_D;
	}
	return graph;
}

enp create_edge(vtype x, vtype y, int weight){
	enp enode = (enp)malloc(sizeof(en));
	enode->weight = weight;
	enode->x = x;
	enode->y = y;
	return enode;
}

void insert_edge(gp graph, enp enode){
	graph->num_e++;
	graph->map[enode->x][enode->y] = enode->weight;	
}

int list_full(int a[], int num){
	for (int i = 0; i < MAX_V; i++){
		if(a[i] == 0){
			return 0;		
		}
	}
	return 1;
}

void print_list(int a[], int num){
	for (int i = 0; i < MAX_V; i++){
		printf("%d ", a[i]);
	}
}

int visited[MAX_V], pre[MAX_V], cost[MAX_V];

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
	for (i = 0; i < MAX_V; i++){
		pre[i] = -1;
		cost[i] = MAX_D;
	}
	
	//put the first node in dij
	visited[0] = 1;
	pre[1] = 0;
	pre[3] = 0;
	cost[1] = 2;
	cost[3] = 1;
	//put the first node in dij
	
	while(1){
		int min = MAX_D, index = -1;
		if (list_full(visited, MAX_V)){
			break;
		}
		for (i = 0; i < MAX_V; i++){
			if (visited[i] == 1){
				for (j = 0; j < MAX_V; j++){
					if (visited[j] == 0 && graph->map[i][j] < min){
						min = graph->map[i][j];
						index = j;
					}
				}
			}
		}
		if (index != -1){
			visited[index] = 1;
			for (j = 0; j < MAX_V; j++){
				if (visited[j] == 0){
					if (cost[index] + graph->map[index][j] < cost[j]){
							cost[j] = cost[index] + graph->map[index][j];
							pre[j] = index;
					}
				}
			}

		}
	}
	print_list(cost, MAX_V);
	putchar('\n');
	print_list(pre, MAX_V);
	return 0;
}
