#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> v[100];

int main() {
	int n, m, x, y;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	
	int s = 1;
	int vi[n];
	for (int i = 1; i <= n ; i++) {
		 vi[i] = 0; 
	}
	queue <int> q;
	q.push(s);
	vi[s] = 1;
	while (!q.empty()) {
		
		int x = q.front();
		q.pop();
		cout << x << " ";
		for (int i = 0; i < v[x].size(); i++){
			if (vi[v[x][i]] == 0){
				q.push(v[x][i]);
				vi[v[x][i]] = 1; 
			}
		}
	}
	return 0;	
}