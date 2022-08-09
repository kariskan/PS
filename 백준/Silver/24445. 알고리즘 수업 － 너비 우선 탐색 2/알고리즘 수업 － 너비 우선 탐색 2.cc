#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, k;
int seq[100001], visit[100001];
vector<vector<int>> v;

bool compare(int& a, int& b) {
	return a > b;
}

int main() {
	cin >> n >> m >> k;
	v.resize(n + 1);

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end(), compare);
	}

	queue<int> q;
	q.push(k);
	visit[k] = 1;
	int cnt = 1;
	while (!q.empty()) {
		int a = q.front();
		q.pop();

		seq[a] = cnt++;

		for (auto& i : v[a]) {
			if (!visit[i]) {
				visit[i] = 1;
				q.push(i);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << seq[i] << '\n';
	}
}