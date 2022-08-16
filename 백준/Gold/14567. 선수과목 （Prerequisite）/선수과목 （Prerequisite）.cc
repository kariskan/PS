#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> v;
int inp[1001], ans[1001];

int main() {

	cin >> n >> m;
	v.resize(n + 1);
	queue<int> q;

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		inp[b]++;
	}

	for (int i = 1; i <= n; i++) {
		if (inp[i] == 0) {
			q.push(i);
			ans[i] = 1;
		}
	}

	while (!q.empty()) {
		int a = q.front();
		q.pop();

		for (auto& i : v[a]) {
			inp[i]--;
			if (inp[i] == 0) {
				q.push(i);
				ans[i] = ans[a] + 1;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << ans[i] << ' ';
	}
}