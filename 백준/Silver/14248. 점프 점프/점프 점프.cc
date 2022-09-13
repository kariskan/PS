#include <iostream>
#include <queue>
using namespace std;
int a[100001], visit[100001];
int main() {
	int n; queue<int> q;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int c; cin >> c;
	q.push(c);
	visit[c] = 1;

	int ans = 0;
	while (!q.empty()) {
		int k = q.front();
		q.pop();

		ans++;

		if (k - a[k] > 0 && !visit[k - a[k]]) {
			visit[k - a[k]] = 1;
			q.push(k - a[k]);
		}
		if (k + a[k] <= n && !visit[k + a[k]]) {
			visit[k + a[k]] = 1;
			q.push(k + a[k]);
		}
	}

	cout << ans;
}