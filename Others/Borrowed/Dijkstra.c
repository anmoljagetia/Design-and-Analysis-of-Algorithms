#include <stdio.h>
#include <conio.h>
#define temp 0
#define perm 1
#define infinity 9999
#define nil -1

int pathlen[8];
int predecessor[8];
int status[8];
int adj[8][8]={ {0,0,2,7,0,0,0,0},
				{0,0,0,0,0,16,0,0},
				{5,0,0,4,0,0,3,0},
				{0,0,0,0,9,0,0,0},
				{4,0,0,0,0,5,0,0},
				{0,0,0,0,0,0,0,0},
				{0,0,6,3,4,0,0,0},
				{0,0,0,0,0,2,5,0}};

int mintemp()
{
	int k,i,min;
	k=nil;
	min = infinity;
	for(i=0;i<8;i++) {
		if(status[i] == temp && pathlen[i] < min) {
			min = pathlen[i];
			k = i;
		}
	}
	return k;
}

void dijkstra(int s)
{
	int i , current;
	for(i=0;i<8;i++) {
		predecessor[i] = nil;
		pathlen[i] = infinity;
		status[i] = temp;
	}
	pathlen[s] = 0;
	while(1) {
		current = mintemp();
		if(current == nil)return;
		status[current] = perm;
		for(i=0;i<8;i++) {
			if(adj[current][i] != 0 && status[i] == temp) {
				if(pathlen[current] + adj[current][i] < pathlen[i]) {
					pathlen[i] = pathlen[current] + adj[current][i];
					predecessor[i] = current;
				}
			}
		}
	}
}

void findpath(int s , int v)
{
	int i,u,sd=0,count=0;
	int path[50];
	while(v!=s) {
		count++;
		path[count] = v;
		u = predecessor[v];
		sd = sd + adj[u][v];
		v=u;
	}
	count++;
	path[count] = s;
	printf("Shortest Path is\n");
	for(i=count;i>=1;i--)printf("%d -> " , path[i]);
		printf("\nShortest Distance is %d" , sd);
}

int main()
{
	int s,v;
	
	printf("Enter source vertex");
	scanf("%d" , &s);
	dijkstra(s);
	printf("Enter destination vertex");
	scanf("%d" , &v);
	findpath(s,v);
	getch();
	return 0;
}
