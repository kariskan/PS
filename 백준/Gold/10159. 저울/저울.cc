#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n, m;
vector<vector<int>> v;
int visit[101][101];
int ans[101];
void run(int idx, int k) {
	
	for (int i = 0; i < v[idx].size(); i++) {
		if (!visit[k][v[idx][i]]) {
			visit[k][v[idx][i]] = 1;
			run(v[idx][i], k);
		}
	}
}
int main() {
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) {
		visit[i][i] = 1;
		run(i, i);
	}
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (visit[i][j] == 0 && visit[j][i] == 0)cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}