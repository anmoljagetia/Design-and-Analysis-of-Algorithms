#include <iostream>
#define SIZE 10
#define swap(x,y) int t; t = x; x = y; y = t;
using namespace std;

int partition (int a[], int p, int r)
{
	int x, i, j;
	x = a[r];
	i = p - 1;
	for (j = p; j < r; j++) {
		if(a[j] <= x) {
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[i + 1], a[r]);
	return i + 1;
}

void quicksort(int a[], int p, int r)
{
	int q;
	// breaking condition of the loop
	if (p < r) {
		q = partition (a, p, r);
		quicksort(a, p, q - 1);
		quicksort(a, q + 1, r);
	}
	
}

int main()
{
	int a[] = {11, 15, 11, 90, 32, 11, 9, 87, 64, 1};
	int i;
	quicksort (a, 0, SIZE - 1);

	// printing sorted array
	for (i = 0; i < SIZE; i++) {
		cout<<a[i]<<"\t";
	}
	return 0;
}


 
