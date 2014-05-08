#include <iostream>
#define SIZE 10
using namespace std;

int Bsearch (int a[], int k, int p, int r)
{
	if (p < r) {
		int m;
		m = (p + r)/2;
		if (a[m] == k) {
			cout << "ELement Found at " << m << "th index" << endl;
			return 1;
		}
		else if (k < a[m]) {
			return Bsearch(a, k, p, m - 1);
		}
		else {
			return Bsearch(a, k, m + 1, r);
		}
	}
	return 0;
}

void status (int s)
{
	if (s == 0) {
		cout << "Element not found" << endl;
	}
}

int main(int argc, char const *argv[])
{
	//given a sorted input array find a elemnt in it in O(logn) time
	int a[] = {1, 1, 9,	11,	11,	15,	32,	64,	87,	90};
	int i, j, k, s;

	//element that I have to find
	k = 45;	//returns not found
	s = Bsearch(a, k, 0, SIZE - 1);
	status(s);
	k = 87; //finds in O(logn) time
	s = Bsearch(a, k, 0, SIZE - 1);
	status(s);
	k = 11; //finds in O(n) time
	s = Bsearch(a, k, 0, SIZE - 1);
	status(s);
	return 0;
}

