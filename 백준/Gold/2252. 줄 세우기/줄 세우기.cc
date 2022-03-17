#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
vector<vector<int>> v;
queue<int> q;
int ind[32001];

int main() {
	
	cin >> n >> m;
	v.resize(n + 1);
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		ind[b]++;
		cnt++;
	}
	for (int i = 1; i <= n; i++) {
		if (!ind[i]) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int a = q.front();
		q.pop();
		cout << a << " ";
		for (int k : v[a]) {
			if (ind[k] == 1) {
				q.push(k);
			}
			ind[k]--;
		}
	}
}