#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	stack<int> s;
	int i, n, e, x, y, cv, f;
	cv = 1;
	cout << "Enter no of nodes" << endl;
	cin >> n;

	cout << "Enter no of edges" << endl;
	cin >> e;

	vector<int> visit;

	vector<int> v[n + 1];
	//created an array of vectors to store the adjacency list n is equal to no of nodes
	//each row of this adjacency list shows the conencted edges of that particular vertex 

	//creating the adjacency list
	for (i = 0; i < e; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x); 
	}

	s.push(cv);
	cout << "BFS of the given graph \n";
	while(s.size() != n) {
		f = (int)s.pop();
		x = v[f][0];
	}

	return 0;
}