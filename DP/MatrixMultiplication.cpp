#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <iostream>

using namespace std;

void MatrixMultiplyOrder(int p[], int SIZE);

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	#endif
	int SIZE;
	cout << "Enter Size" << endl;
	cin >> SIZE;
	int p[SIZE];
	int i;
	cout << "Enter " << SIZE << " elements" << endl;
	for (i = 0; i < SIZE; i++) {
		scanf("%d", &p[i]);
	}
	MatrixMultiplyOrder (p, SIZE);
	return 0;
}

void MatrixMultiplyOrder (int p[], int SIZE)
{
	int m[SIZE + 1][SIZE + 1];
	int i;
	int j;
	int k;
	int l;
	int q = 0;
	int n = SIZE;

	for (i = 0; i <= SIZE; i++) {
		for (j = 0; j <= SIZE; j++) {
			m[i][j] = 0;		
		}	
	}

	//stored data by taking one element each
	for (i = 1; i <= n; i++) {
		m[i][i] = 0;
	}

	//because in A1A2A3 we have to start with taking atlest two elements
	//'l' shows the length of the input we are taking into consideration
	for (l = 2; l <= n; l++) {
		//'i' points out which elements are taken into consideration
		for (i = 1; i <= n - l + 1; i++) {
			j = l + i - 1;
			m[i][j] = INT_MAX;

			//'k' points out the partition
			for (k = i; k <= j - 1; k++) {
				q = m[i][k] + m[k + 1][j] + p[i - 1]*p[k]*p[j];
				if (q < m[i][j]) {
					m[i][j] = q;
				}
			}
		}
	}
	
	for (i = 1; i < SIZE; i++) {
		for (j = 1; j < SIZE; j++) {
			cout << m[i][j] << "\t";
		}
		cout << endl;
	}
}
