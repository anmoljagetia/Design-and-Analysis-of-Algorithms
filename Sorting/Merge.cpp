#include <iostream>
#include <limits.h>
#define SIZE 10

using namespace std;

void merge (int a[], int p, int r, int q)
{
	int n, m, i, j, k;
	n = q - p + 1;
	m = r - q;
	int x[n + 1], y[m + 1];

	//Copy left half into x[] array
	for(i = 0; i < n; i++) {
		x[i] = a[p + i];
	}

	//Copy right half into y[] array
	for (j = 0; j < m; j++) {
		y[j] = a[q + j + 1];
	}

	x[n] = INT_MAX;
	y[m] = INT_MAX;

	i = 0;
	j = 0;

	//copy the sorted elements into the main array by comparing elements in
	//x[] and y[] arrays respectively
	for (k = p; k <= r; k++) {
		if(x[i] < y[j]) {
			a[k] = x[i];
			i++;
		}
		else {
			a[k] = y[j];
			j++;
		}
	}
}

void mergesort(int a[], int p, int r)
{
	if (p < r) {
		int q = (p + r) / 2;
		mergesort(a, p, q);
		mergesort(a, q + 1, r);
		merge(a, p, r, q);
	}
}

int main()
{
	int a[] = {11, 15, 11, 90, 32, 11, 9, 87, 64, 1};
	int i;
	mergesort(a, 0, SIZE - 1);

	// printing sorted array
	for (i = 0; i < SIZE; i++) {
		cout<<a[i]<<"\t";
	}
	return 0;
}

