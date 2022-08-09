#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int visit[300001], n;
vector<vector<int>> v;

int main() {
	cin >> n;
	v.resize(n + 1);

	for (int i = 0; i < n - 2; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			cnt++;

			queue<int> q;
			visit[i] = cnt;
			q.push(i);

			while (!q.empty()) {
				int a = q.front();
				q.pop();

				for (auto& i : v[a]) {
					if (!visit[i]) {
						visit[i] = cnt;
						q.push(i);
					}
				}
			}
		}
	}

	int f, d;
	for (int i = 1; i <= n; i++) {
		if (visit[i] == 1)f = i;
		if (visit[i] == 2)d = i;
	}

	cout << f << ' ' << d;
}