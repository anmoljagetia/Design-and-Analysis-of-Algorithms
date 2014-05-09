#include <iostream>
#include <vector>
using namespace std;

void dfsVisit (vector<int> v[], int u, int visit[], int n)
{
	int i, j;
	visit[u] = 0;
	
	for (j = 0; j < v[u].size(); j++) {
		if (visit[v[u][j]] == -1) {
			dfsVisit(v, v[u][j], visit, n);
		}
	}
	visit[u] = 1;
	cout << u << " ";
}

void dfs(int n, int e)
{
	int i, j, x, y;
	int visit[n + 1];
	vector<int> v[n + 1];
	//created an array of vectors to store the adjacency list n is equal to no of nodes
	//each row of this adjacency list shows the conencted edges of that particular vertex 

	//creating the adjacency list
	for (i = 0; i < e; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x); 
	}

	for (i = 1; i <= n; i++) {
		visit[i] = -1;
	}

	for (i = 1; i <= n; i++) {
		for (j = 0; j < v[i].size(); j++) {
			if (visit[v[i][j]] == -1) {
				dfsVisit(v, v[i][j], visit, n);
			}
		}
	}
}


int main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif

	int i, n, e, x, y, cv, j;
	cout << "Enter no of nodes" << endl;
	cin >> n;

	cout << "Enter no of edges" << endl;
	cin >> e;
	dfs(n, e);
	return 0;
}
