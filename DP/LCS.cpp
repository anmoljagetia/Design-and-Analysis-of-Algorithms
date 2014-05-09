#include <iostream>
#include <string>

using namespace std;
char y[100][100];
void printLCS (int m, int n, string a);

int lcs (string a, string b, int m, int n)
{
	int i, j;
	//matrix that computes LCS
	int x[m + 1][n + 1];
	//matrix that stores the direction to find the actual string
	//char y[m + 1][n + 1];
	for (i = 0; i <= m; i++) {
		for (j = 0; j <= n; j++) {
			if(i == 0 || j == 0) {
				x[i][j] = 0;
				y[i][j] = 'g'; 
			}
			else if (a[i - 1] == b[j - 1]) {
				x[i][j] = x[i - 1][j - 1] + 1;
				y[i][j] = 'd';
			}
			else {
				if(x[i - 1][j] > x[i][j - 1]) {
					x[i][j] = x[i - 1][j];
					y[i][j] = 'u';
				}
				else if(x[i - 1][j] < x[i][j - 1]) {
					x[i][j] = x[i][j - 1];
					y[i][j] = 'r';
				}
			}
		}
	}
	return x[m][n];
}

void printLCS (int m, int n, string a)
{
	if(m == 0 || n == 0) {
		return;
	}
	if (y[m][n] == 'd') {
		printLCS(m - 1, n - 1, a);
		cout << a[m - 1];
	}
	else if (y[m][n] == 'u') {
		printLCS(m - 1, n, a);
	}
	else {
		printLCS(m, n- 1, a);
	}
}

int main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	int m, n;
	string a, b;
	cin >> a;
	cin >> b;
	m = a.length();
	n = b.length();
	cout << "The Length of LCS is " << lcs (a, b, m, n) << endl;
	cout << "The LCS is " ;
	printLCS(m, n, a);
	return 0;
}

