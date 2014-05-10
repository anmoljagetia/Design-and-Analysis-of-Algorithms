#include <iostream>
#include <map>
#define n 3
#define max(a,b) a > b ? a: b;

using namespace std;
		
int Knapsack(int w, int wt[], int val[])
{
	int i, j;
	// matrix that will store our DP solution
	int k[n + 1][ w + 1];

	for (i = 0; i <= w; i++) {
		k[0][i] = 0;
	}

	for (i = 1; i <= n; i++) {
		for (j = 0; j <= w; j++) {
			if (j == 0) {
				k[i][j] = 0;
			}
			//weight of the particular item is less than our limit 
			else if (wt[i - 1] <= w) {
				//taking max value in the cases when we
				//1. Take the ith element
				//2. Do not take the ith element
				k[i][j] = max (val[i - 1] + k[i - 1][j - wt[i - 1]], k[i - 1][j]);
			}
			else {
				//else skip the element and the max value remains the same
				k[i][j] = k [i - 1][j];
			}
		}
	}

	//THis was used to print out the full array during debugging
	// for (i = 0; i <= n; i++) {
	// 	for (j = 0; j <= w; j++) {
	// 		cout << k[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	return k[n][w];
}

int main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int w;
	cout << "Enter weight of bag " << endl;
	cin >> w;
    cout << Knapsack (w, wt, val) << endl;
	return 0;
}

