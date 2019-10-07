#include <stdio.h>
#include <stdlib.h>

int ifPath(int row, int column, int** layout, int x, int y, int** flag) {
	flag[x][y] = 1;
	if(layout[x][y]==9)
		return 1;
	if(layout[x][y]==0)
		return 0;
	int a, b, c, d;
	if(x-1>=0 && layout[x-1][y]!=0 && flag[x-1][y]!=1)
		a = ifPath(row, column, layout, x-1, y, flag);
	if(x+1<=row && layout[x+1][y]!=0 && flag[x+1][y]!=1)
		b = ifPath(row, column, layout, x+1, y, flag);
	if(y-1>=0 && layout[x][y-1]!=0 && flag[x][y-1]!=1)
		c = ifPath(row, column, layout, x, y-1, flag);
	if(y+1<=column && layout[x][y+1]!=0 && flag[x][y+1]!=1)
		d = ifPath(row, column, layout, x, y+1, flag);
	return (a || b || c || d);
}

int isPath(int row, int column, int** layout) {
	int **flag, i, j;
	flag = (int**)malloc(row*sizeof(int*));
	for(i=0;i<row;i++)
		flag[i] = (int*)malloc(column*sizeof(int));
	for(i=0;i<row;i++)
		for(j=0;j<column;j++)
			flag[i][j] = 0;
	for(i=0;i<row;i++) {
		for(j=0;j<column;j++)
			printf("%d/%d ", layout[i][j], flag[i][j]);
		printf("\n");
	}
	int x = ifPath(row, column, layout, 0, 0, flag);
	for(i=0;i<row;i++)
		free(flag[i]);
	free(flag);
	return x;
}

int main(int argc, char const *argv[])
{
	int row, column, **layout, i, j;
	scanf("%d%d", &row, &column);
	layout = (int**)malloc(row*sizeof(int*));
	for(i=0;i<row;i++)
		layout[i] = (int*)malloc(column*sizeof(int));
	for(i=0;i<row;i++) {
		for(j=0;j<column;j++)
			scanf("%d", &layout[i][j]);
		printf("\n");
	}
	printf("answer: %d\n", isPath(row, column, layout));
	for(i=0;i<row;i++)
		free(layout[i]);
	free(layout);
	return 0;
}