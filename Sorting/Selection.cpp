#include <iostream>
#define SIZE 10
using namespace std;

int main(int argc, char const *argv[])
{
	int a[] = {11, 15, 11, 90, 32, 11, 9, 87, 64, 1};
	int i, j, k, t, m;

	for (i = 0; i < SIZE; i++) {
		k = a[i];
		m = i;
		for (j = i; j < SIZE; j++) {
			if (a[j] < a[m]) {
				m = j;
			}
		}
		a[i] = a[m];
		a[m] = k;
	}

	//printing sorted array
	for (i = 0; i < SIZE; i++) {
		cout<<a[i]<<"\t";
	}

	return 0;
}
 