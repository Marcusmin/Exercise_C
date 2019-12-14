#include <stdio.h>

int main(void){
	int ne, nv;
	scanf("%d %d", &nv, &ne);
	int map[nv][nv];
	for (int i = 0; i < nv; i++){
		for (int j = 0; j < nv; j++){
			map[i][j] == 0;
		}
	}
	int i = 0;
	while (i < ne){
		int v1, v2 ,w;
		printf("please enter edge information\n");
		scanf("%d %d %d", &v1, &v2, &w);
		map[v1][v2] = w;
		map[v2][v1] = w;	
	}	


	return 0;
}
