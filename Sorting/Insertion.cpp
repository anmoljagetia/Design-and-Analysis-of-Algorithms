#include <iostream>
#define SIZE 10
using namespace std;

int main(int argc, char const *argv[])
{
	int a[] = {11, 15, 11, 90, 32, 11, 9, 87, 64, 1};
	int i, j, k;

	for (j = 1; j < SIZE; j++) {
		k = a[j];	//copy the element into key
		i = j - 1;	//i will vary uptil j - 1 because we might have to sort elements until the current one

		//to insert the element into the correct position we have
		//to keep on going until we find its correct position
		//It is done by comparing elemnts and then moving down in array unless we go out of range
		// ie (i < 0) or we encounter a smaller element
		while (i >= 0 && a[i] > k) {
			a[i + 1] = a[i];
			i = i - 1;
		}
		a[i + 1] = k;
	}

	//printing sorted array
	for (i = 0; i < SIZE; i++) {
		cout << a[i] << "\t";
	}

	return 0;
}
 