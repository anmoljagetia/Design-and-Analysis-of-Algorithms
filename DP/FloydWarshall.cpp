#include <iostream>
#include <limits.h>
#define INF 9999
#define n 4
#define min(a,b) a < b ? a: b;

using namespace std;

void printSol (int d[][n])
{
	int i, j;

	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			if(d[i][j] == INF) {
				cout << "INF" << " ";
			} else {
				cout << d[i][j] << " ";
			}
		}
		cout << endl;
	}
}

void FloydWarshall(int g[][n])
{
	int i, j, k;
	int d[n][n];

	// initializing the final distance matrix
	// with the same distance as input graph 
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			d[i][j] = g[i][j];
		}
	}

	// actual algorithm where 
	// k 
	// i and j identify element in the array
	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = (d[i][k] + d[k][j]);
				}
			}
		}
	}

	printSol (d);

}

int main(int argc, char const *argv[])
{
	int i, j;
	int g[n][n] = { {0,   5,  INF, 10},
                    {INF,  0,  3,  INF},
                    {INF, INF, 0,   1},
                    {INF, INF, INF, 0} };
	FloydWarshall(g);
	return 0;
}

