#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <conio.h>

using namespace std;

vector<pair<int, int> > v;
vector<pair<int, int> > d;
int vi[100] = {0};
int n = 15;
int arr[] = {0, 1, 2, 2, 2, 3, 3, 3, 4, 5, 5, 5, 6, 7, 8, 10};

void print() {
	int i;
	for (i = 0; i < v.size(); i++) {
		cout << arr[v[i].first] << " ";
	}
	cout << endl;
	for (i = 0; i < d.size(); i++) {
		cout << arr[d[i].first] << " ";
	}
	cout << endl;
}


int search(int l) {
	int i;
	for (i = 1; i <= 15; i++) {
		if (arr[i] == l && vi[i] == 0) return i;
	}
	return -1;
}

bool solve(int n, int ts) {
	//cout << "N = " << n << endl;
	bool t = true, test;
	if (n == 0) return true;
	if (vi[n] == 1) {
		print();
		return solve(n - 1, ts + 1); 
	}
	int i;
	int h = arr[n];
	vi[n] = 1;
	int size = v.size();
	for (i = 0; i < size; i++) {
		int ind = search(abs(h - arr[v[i].first]));
		if (ind != -1) {
			d.push_back(make_pair(ind, ts));
			vi[ind] = 1;
		} else {
			int j;
			vector <pair<int, int> >:: iterator it = d.begin();
			for (it; it != d.end(); ++it) {
				if (it->second == ts) {
					vi[it->first] = 0;
					d.erase(it);
					it--;
				}
			}
			vi[n] = 0;
			t = false;
			break;
		}
	}
	if (t == true) {
		v.push_back(make_pair(n, ts)); 
		vi[n] = 1;
		test = solve(n - 1, ts + 1);
		if (test == true) {
			print();
			return true;
		}
	}

	if (test == false) {
		vector <pair<int, int> >:: iterator it = d.begin();
		for (it; it != d.end(); ++it) {
			if (it->second == ts) {
				vi[it->first] = 0;
				d.erase(it);
				it--;
			}
		}
		for (it = v.begin(); it != v.end(); ++it) {
			if (it->second == ts) {
				vi[it->first] = 0;
				v.erase(it);
				it--;
			}
		}
	}

//first part ends here i.e (h)


	int l = 10 - arr[n];
	int li = search(l);
	if (li == -1) {
		print();
		return false;
	}
	vi[li] = 1;
	size = v.size();
	for (i = 0; i < size; i++) {
		int ind = search(abs(l - arr[v[i].first]));
		if (ind != -1) {
			d.push_back(make_pair(ind, ts));
			vi[ind] = 1;
		} else {
			int j;
			vector <pair<int, int> >:: iterator it = d.begin();
			for (it; it != d.end(); ++it) {
				if (it->second == ts) {
					vi[it->first] = 0;
					d.erase(it);
					it--;
				}
			}
			vi[li] = 0;
			print();
			return false;
		}
	}
	v.push_back(make_pair(li, ts)); // first part ends here
	vi[li] = 1;
	t = solve(n - 1, ts + 1);
	if (t == false) {
		vector <pair<int, int> >:: iterator it = d.begin();
		for (it; it != d.end(); ++it) {
			if (it->second == ts) {
				vi[it->first] = 0;
				d.erase(it);
				it--;
			}
		}
		for (it = v.begin(); it != v.end(); ++it) {
			if (it->second == ts) {
				vi[it->first] = 0;
				v.erase(it);
				it--;
			}
		}
		print();
		return false;
	} else {
		print();
		return true;
	}
}

int main()
{
	v.push_back(make_pair(15, 0));
	vi[15] = 1;
	bool b = solve(14, 1);
	if (b == true) {
		int i;
		for (i = 0; i < v.size(); i++) {
			cout << arr[v[i].first] << " ";
		}
	}
	getch();
	return 0;
}
