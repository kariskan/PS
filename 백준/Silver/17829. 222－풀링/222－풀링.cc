#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int get(int a, int b, int c, int d) {
	vector<int> v = { a,b,c,d };
	sort(v.begin(), v.end());
	return v[2];
}

void go(vector<vector<int>> v, int m) {
	if (m == 1) {
		cout << v[0][0];
		exit(0);
	}

	vector<vector<int>> k(m / 2);

	for (int i = 0; i < m; i += 2) {
		for (int j = 0; j < m; j += 2) {
			k[i / 2].push_back(get(v[i][j], v[i][j + 1], v[i + 1][j], v[i + 1][j + 1]));
		}
	}

	go(k, m / 2);
}

int main() {
	cin >> n;
	vector<vector<int>> v(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}

	go(v, n);
}