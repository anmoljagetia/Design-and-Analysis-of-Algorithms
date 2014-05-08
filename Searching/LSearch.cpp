#include <iostream>
#define SIZE 10
using namespace std;

int main(int argc, char const *argv[])
{
	int a[] = {11, 15, 11, 90, 32, 11, 9, 87, 64, 1};
	int i, j, k;

	//element that I have to find
	k = 45;	//returns not found
	k = 87; //finds in O(n) time
	j = -1;
	for (i = 0; i < SIZE; ++i) {
		if(a[i] == k) {
			j = i;
		}
	}

	if(j == -1) {
		cout << "Element not found" << endl;
	}
	else {
		cout << "Element found at " << j << "th index of array" << endl;
	}

	return 0;
}
 