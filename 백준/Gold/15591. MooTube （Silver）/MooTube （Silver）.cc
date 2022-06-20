#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n, q;
vector<vector<pair<int, int>>> v;
bool visit[5001];
int ans = 0;
void run(int k, int b, int idx, int sum) {
	if (b != idx && sum >= k) {
		ans++;
	}
	for (int i = 0; i < v[idx].size(); i++) {
		if (!visit[v[idx][i].first]) {
			visit[v[idx][i].first] = 1;
			run(k, b, v[idx][i].first, min(sum, v[idx][i].second));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> q;
	v.resize(n + 1);
	
	for (int i = 1; i < n; i++) {
		int a, b;
		int c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	for (int i = 0; i < q; i++) {
		int k, b;
		cin >> k >> b;
		ans = 0;
		visit[b] = 1;

		run(k, b, b, 1000000000);
		cout << ans << "\n";
		memset(visit, false, sizeof(visit));
	}
}