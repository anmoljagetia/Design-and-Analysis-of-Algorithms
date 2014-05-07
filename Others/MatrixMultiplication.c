#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#define SIZE 5

void MatrixMultiplyOrder(int p[]);

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	int p[SIZE];
	int i;
	for (i = 0; i < SIZE; i++) {
		scanf("%d", &p[i]);
	}

	MatrixMultiplyOrder (p);
	scanf("%d", &i);
	return 0;
}

void MatrixMultiplyOrder (int p[SIZE])
{
	int m[SIZE + 1][SIZE + 1] = {0};
	int i;
	int j;
	int k;
	int l;
	int q;
	int n = SIZE;
	//stored data by taking one element each
	for (i = 1; i <= n; i++) {
		m[i][i] = 0;
	}

	//because in A1A2A3 we have to start with taking atlest two elements
	for (l = 2; l <= n; l++) {
		for (i = 1; i <= n - l + 1; i++) {
			j = l + i - 1;
			m[i][j] = INT_MAX;

			for (k = i; k <= j - 1; k++) {
				q = m[i][k] + m[k + 1][j] + p[i - 1]*p[k]*p[j];
				if (q < m[i][j]) {
					m[i][j] = q;
				}
			}
		}
	}

	printf("%d\n", q);

		/*for (i = 1; i < SIZE; i++) {
			for (j = 1; j < SIZE; j++) {
				printf("%d  ", m[i][j]);
			}
			printf("\n");
		}*/
	}

//Recursive Solution for the same problem.
//It is not as good as Dynamic Programming because it 
//will recompute values. 
/*{
	if (i == j) {
		return 0;
	}

	int 
}*/