#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n, m;
int inp[32001];
int main() {

	cin >> n >> m;
	vector<vector<int>> v(n + 1);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		inp[b]++;
		v[a].push_back(b);
	}
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 1; i <= n; i++) {
		if (inp[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int a = q.top();
		q.pop();
		cout << a << ' ';

		for (int i = 0; i < v[a].size(); i++) {
			if (--inp[v[a][i]] == 0) {
				q.push(v[a][i]);
			}
		}
	}
}