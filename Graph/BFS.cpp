#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	queue<int> q;
	int i, n, e, x, y, cv, f;
	cv = 1;
	cout << "Enter no of nodes" << endl;
	cin >> n;

	cout << "Enter no of edges" << endl;
	cin >> e;

	int visit[n + 1];

	for (i = 1; i <= n; ++i) {
		visit[i] = 0;
	}

	vector<int> v[n + 1];
	//created an array of vectors to store the adjacency list n is equal to no of nodes
	//each row of this adjacency list shows the conencted edges of that particular vertex 

	//creating the adjacency list
	for (i = 0; i < e; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x); 
	}

	q.push(cv);
	visit[cv] = 1;

	cout << "BFS of the given graph \n";
	while(!q.empty()) {
		f = q.front();
		q.pop();
		cout << f << " ";

		//until all connected vertices are in the queue
		for(i = 0; i < v[f].size(); i++)  {
			//if not previously visited
			if (visit[v[f][i]] == 0) {
				//push in queue and and the vertex to visited list
				q.push(v[f][i]);
				visit[v[f][i]] = 1;
			}
		}
	}

	return 0;
}