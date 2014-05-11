#include <iostream>
#include <stdio.h>
#include <cstdio>

using namespace std;

void countingSort (int a[], int k, int s)
{
	int i;
	int c[k];	
	int b[s];
	//will store cummalative count of the array, initializing it to zero
	for (i = 0; i < k; i ++) {
		c[i] = 0;
	}

	//each index contains count of that element in input array
	for(i = 0; i < s; i++) {
		c[a[i]]++;
	}

	//cummalative sum of all the arrays
	for(i = 1; i < k; i++) {
		c[i] = c[i - 1] + c[i];	
	}

	//putting thre elements in their correct position
	//decrementing the cummalative array
	for(i = s - 1; i >= 0; i--) {
		b[c[a[i]] - 1] = a[i];
		c[a[i]] = c[a[i]] - 1;
	}

	for (i = 0; i < s; ++i) {
		cout << b[i] << " ";
	}
}

int main(int argc, char const *argv[])
{
	int i, j, k;
	int a[] = {2, 5, 3, 0, 2, 3, 0, 3};
	int s = sizeof (a)/ sizeof(a[0]);
	k = 6;	//The range of input numbers
	countingSort(a, k, s); 
	return 0;
}