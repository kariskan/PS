#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int k, m, p;
		cin >> k >> m >> p;

		int inp[1001] = { 0, };
		pair<int, int> info[1001] = {};
		vector<vector<int>> v(m + 1);

		for (int i = 0; i < p; i++) {
			int a, b; cin >> a >> b;
			v[a].push_back(b);
			inp[b]++;
		}

		queue<int> q;

		for (int i = 1; i <= m; i++) {
			if (inp[i] == 0) {
				info[i].first = 1;
				q.push(i);
			}
		}

		while (!q.empty()) {

			int a = q.front();
			q.pop();

			for (auto& i : v[a]) {
				
				if (--inp[i] == 0)q.push(i);

				if (info[i].first < info[a].first) {
					info[i].first = info[a].first;
					info[i].second = 1;
				}
				else if (info[i].first == info[a].first) {
					if (info[i].second >= 1) {
						info[i].first++;
						info[i].second = 0;
					}
					else {
						info[i].second++;
					}
				}

			}
		}

		cout << k << ' ' << info[m].first << '\n';
	}


}