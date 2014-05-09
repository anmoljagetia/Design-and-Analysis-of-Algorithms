#include <iostream>
#include <string>
#include <limits.h>
#define max(a,b) a > b ? a : b;
using namespace std;

int rodCutting (int r[], int l)
{
	int p[l + 1];
	int i, j, q;
	p[0] = 0;
	for (i = 1; i <= l; i++) {
		q = -9999999;
		for (j = 1; j <= i; j++) {
			q = max(q, p[i - j] + r[j]);
		}
		p[i] = q;
	}
	return p[l];
}

int main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	int r[5], l, i;;
	r[0] = 0;
	r[1] = 1;
	r[2] = 5;
	r[3] = 8;
	r[4] = 9;
	cout << "Enter Length of rod" << endl;
	l = 7;
	cout << "The best price is " << rodCutting(r, l);
	cout << endl;
	return 0;
}

