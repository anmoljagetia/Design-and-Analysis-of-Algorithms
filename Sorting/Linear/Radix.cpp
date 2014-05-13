#include <iostream>
#include <stdio.h>
#include <cstdio>

using namespace std;

int getMax(int a[], int s)
{
    int max = a[0];
    for (int i = 1; i < s; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

void countingSort (int a[], int s, int e)
{
	int i;
	int b[s];
	int c[10];	

	// //will store cummalative count of the array, initializing it to zero
	for (i = 0; i < 10; i ++) {
		c[i] = 0;
	}

	//each index contains count of that element in input array
	//the divide by e will get the place (unit, tens, hundreds) required
	//and the %10 gets the digit at that location
	for(i = 0; i < s; i++) {
		c[(a[i]/e)% 10]++;
	}

	//cummalative sum of all the the full
	//array used to find the location at which the elements will go
	for(i = 1; i < 10; i++) {
		c[i] = c[i - 1] + c[i];	
	}

	//putting thre elements in their correct position
	//decrementing the cummalative array
	for(i = s - 1; i >= 0; i--) {
		b[c[(a[i]/e) % 10] - 1] = a[i];
		c[(a[i]/e) % 10] = c[(a[i]/e) % 10] - 1;
	}

	for (i = 0; i < s; ++i) {
		a[i] = b[i];
	}
}


void radixSort (int a[], int s) 
{
	int m, e;
	m = getMax(a, s);

	for (e = 1; m/e > 0; e = e * 10) {
		countingSort(a, s, e);
	}
}	

int main(int argc, char const *argv[])
{
	int i, j, k, d;
	int a[] = {329, 457, 657, 839, 436, 720, 355};
	int s = sizeof (a)/ sizeof(a[0]);
	radixSort(a, s); 

	//printing the sorted array
	for (i = 0; i < s; i++) {
		cout << a[i] << " ";
	}
	return 0;
}