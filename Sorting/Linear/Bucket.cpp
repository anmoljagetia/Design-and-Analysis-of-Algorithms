#include <iostream>
#include <list>
using namespace std;

int main(int argc, char const *argv[])
{
	//read input from a file in.txt as std input
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	//for numbers between 0 and 100
	list<int> b[11];
	list<int>::iterator it;
	int i, j, k, n, a, c;
	cout << "Enter no of elements " << endl;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a;
		k = a/ 10;
		c = 0;
		it = b[k].begin();
		// used to insert the first element of the bucket
		if(b[k].size() == 0) {
			b[k].insert(it, a);
			c = 1;
		}
		//used to insert more elements
		//usually the middle ones
		for (it = b[k].begin(); it != b[k].end(); it++) {
			if(a < (*it) && c == 0) {
				b[k].insert(it, a);
				c = 1;
				break;
			}
		}

		//used to insert at the last of the list
		if (c != 1) {
			b[k].push_back(a);
		}
	
	}
	
	// printing the sorted output
	for(i = 0; i <= 10; i++) {
		for (it = b[i].begin(); it != b[i].end(); it++) {
			cout << ' ' << *it;
		}
		cout << endl;
	}
	return 0;
}
