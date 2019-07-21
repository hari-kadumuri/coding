#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

typedef struct _node {
	double x;
	double y;
	int class;
}Node;

double getDistance(Node a, Node b) {
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int IterativeAssign(Node* nodes, Node* classcenters, int n, int k) {
	int i, flag = 0;
	for(i=0;i<n;i++) {
		int j;
		for(j=0;j<k;j++) {
			if(j!=nodes[i].class && getDistance(nodes[i], classcenters[j])<getDistance(nodes[i], classcenters[nodes[i].class])) {
				nodes[i].class = j;
				flag = 1;
			}
		}
	}
	return flag;
}

void ReCalculateCenters(Node* nodes, Node* classcenters, int n, int k) {
	int i;
	for(i=0;i<k;i++) {
		double sumx = 0, sumy = 0;
		int j;
		for(j=0;j<n;j++) {
			if(nodes[j].class!=i)
				continue;
			sumx += nodes[j].x;
			sumy += nodes[j].y;
		}
		if(sumx!=0) classcenters[i].x = (double)sumx/n;
		if(sumy!=0) classcenters[i].y = (double)sumy/n;
	}
}

int K_MeansClassify(Node* nodes, int n, int k) {
	Node classcenters[k];
	int i;
	for(i=0;i<k;i++) {
		classcenters[i].x = classcenters[i].y = rand()%100;
		classcenters[i].class = i;
	}
	int flag = 1, count = 0;
	while(flag) {
		flag = IterativeAssign(nodes, classcenters, n, k);
		ReCalculateCenters(nodes, classcenters, n, k);
		count++;
	}
	return count;
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int k = rand()%100, n = k + rand()%250;
	printf("n = %d\tk = %d\n", n, k);
	Node nodes[n];
	int i;
	for(i=0;i<n;i++) {
		nodes[i].x = rand()%99 + (double)rand()/RAND_MAX;
		nodes[i].y = rand()%99 + (double)rand()/RAND_MAX;
		nodes[i].class = 0;
	}
	int count = K_MeansClassify(nodes, n, k);
	printf("After Classification:\nIndex\tAbscissa(x)\tOrdinate(y)\tClass\n");
	for(i=0;i<n;i++)
		printf("%d\t%lf\t%lf\t%d\n", i, nodes[i].x, nodes[i].y, nodes[i].class);
	printf("no of iterations till convergence = %d\n", count);
	printf("<-----------------------------------------------------------------------------\n");
	return 0;
}