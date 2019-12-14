#include <stdio.h>
#include <stdlib.h>
#define MAX_V 7
#define MAX_E 12
#define MAX_D 9999

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
	int i, j, k;
	vtype cost[MAX_V][MAX_V];
	for (i = 0; i < MAX_V; i++){
		for (j = 0; j < MAX_V; j++){
			cost[i][j] = graph->map[i][j];
		}
	}
	for (i = 0; i < MAX_V; i++){
		for (j = 0; j < MAX_V; j++){
			for (k = 0; k < MAX_V; k++){
				if(graph->map[i][k] + graph->map[k][j] < graph->map[i][j]){
					cost[i][j] = graph->map[i][k] + graph->map[k][j];
				}
			}			
		}
	}
	for (i = 0; i < MAX_V; i++){
		for (j = 0; j < MAX_V; j++){
			printf("%5d ", cost[i][j]);
		}
		putchar('\n');
	}
	return 0;
}
