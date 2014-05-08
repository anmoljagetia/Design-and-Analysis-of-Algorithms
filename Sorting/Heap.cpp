#include <iostream>
#define SIZE 10
#define swap(x,y) int t; t = x; x = y; y = t;
using namespace std;

void heapify (int a[], int i, int n)
{
	//compare node, lchild and rchild and if node is not the largest
	//swaps it with its child and then calls heapify again to restore the heap property
	int l, r, largest;
	l = (2 * i) + 1;
	r = (2 * i) + 2;
	if(l <= n && a[l] > a[i]) {
		largest = l;
	} else {
		largest = i;
	}
	if (r <= n && a[r] > a[largest]) {
		largest = r;
	}
	if (largest != i) {
		swap(a[i], a[largest]);
		heapify(a, largest, n);
	}
}

void buildMaxHeap (int a[], int n) 
{
	int i;
	//only for non-leaf nodes.
	//we will call heapify upon each one of them.
	for (i = (SIZE/2) ; i >= 0; i--) {
		heapify(a, i, n);
	}
}


void heapsort (int a[])
{
	int n, i;
	n = SIZE;
	buildMaxHeap(a, n - 1);
	for (i = SIZE - 1; i > 0; i--) {
		swap (a[0], a[i]);
		n--;
		//extract the root of the tree and then put the last element in its place
		// then call upon heapify again to restore heap property
		heapify(a, 0, n - 1);
	}
}

int main()
{
	int i;
	int a[] = {11, 15, 11, 90, 32, 11, 9, 87, 64, 1};
	heapsort (a);

	// printing sorted array
	for (i = 0; i < SIZE; i++) {
		cout << a[i] << "\t";
	}

	return 0;
}


 
