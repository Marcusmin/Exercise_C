#include <stdio.h>
#define END_X 3
#define END_Y 0
#define LENGTH_A 4
#define LENGTH 3
int map[LENGTH_A][LENGTH_A] = {
	{1,1,0,0},
	{0,1,1,1},
	{1,1,0,1},
	{1,0,0,1}
};

//int mark[4][4] = map;
int move[4][2] = {
	{1,0},
	{-1,0},
	{0,1},
	{0,-1}
};

int dfs(int x, int y){
	printf("x = %d  y = %d\n", x, y);
	if (x == END_X && y == END_Y){
		return 1; //赋值给上一次的flag，并返回到flag所在层
	}
	else{
		for (int i = 0; i < 4; i++){
			if (x+move[i][0] > LENGTH || x+move[i][0] < 0 || y+move[i][1] > LENGTH || y+move[i][1] < 0 || map[x+move[i][0]][y+move[i][1]] == 0){
				continue;
			}
			map[x+move[i][0]][y+move[i][1]] = 0;
			int flag = dfs(x+move[i][0], y+move[i][1]);
			map[x+move[i][0]][y+move[i][1]] = 1;
			if (flag == 1){
				return 1;//赋值给函数体，并返回到main层
			}
		}
		return 0;
	}
	
}



int main(void){
	int flag = dfs(0, 0);
	if (flag == 1){
		printf("can get out!!\n");
	}
	else{
		printf("no answer~");
	}
	return 0;
}
