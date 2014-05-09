#include <iostream>
#include <string>

using namespace std;

int lis (int a[], int n)
{
	int i, j, max;
	int l[n];
	max = 0;
	//initializing all to 1(min LIS)
	for (i = 0; i < n; ++i) {
		l[i] = 1;
	}

	for (i = 1; i < n; i++) {
		for (j = 0; j < i; j++) {
			if (a[i] > a[j] && l[i] <= l[j] ) {
				l[i] = l[j] + 1;
			}
		}
	}

	for (i = 0; i < n; i++) {
		if(max < l[i]) {
			max = l[i];
		}
	}
	return max;
}

int main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	int n, i;
	cout << "Enter size of sequence" << endl;
	cin >> n;
	int a[n];
	cout << "Enter " << n << " numbers " << endl;
	for (i = 0; i < n; ++i) {
		cin >> a[i];
	}

	cout << "Length of LIS is " << lis(a, n);
	return 0;
}

