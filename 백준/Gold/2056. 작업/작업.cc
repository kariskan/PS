#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int w[10001];
int ind[10001];
int now[10001];
int main() {
	int n;
	cin >> n;
	vector<vector<int>> v(n + 1);
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		w[i] = a;
		ind[i] += b;
		for (int j = 0; j < b; j++) {
			int c;
			cin >> c;
			v[c].push_back(i);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!ind[i]) {
			q.push(i);
			now[i] += w[i];
			ans = max(ans, now[i]);
		}
	}
	while (!q.empty()) {
		int a = q.front();
		q.pop();
		for (int k : v[a]) {
			now[k] = max(now[k], now[a] + w[k]);
			if (ind[k] == 1) {
				ans = max(ans, now[k]);
				q.push(k);
			}
			ind[k]--;
		}
	}
	cout << ans;
}

