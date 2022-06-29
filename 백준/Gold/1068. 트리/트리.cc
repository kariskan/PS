#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;
int n, d;

int getLeaf(int idx) {
	if (v[idx].empty())return 1;
	int leafSum = 0;
	for (int i = 0; i < v[idx].size(); i++) {
		if (v[idx][i] == d)continue;
		leafSum += getLeaf(v[idx][i]);
	}
	return leafSum == 0 ? 1 : leafSum;
}

int main() {
	cin >> n;
	v.resize(n);
	int root = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a == -1) {
			root = i;
			continue;
		}
		v[a].push_back(i);
	}
	cin >> d;
	if (d == root)cout << 0;
	else cout << getLeaf(root);
}