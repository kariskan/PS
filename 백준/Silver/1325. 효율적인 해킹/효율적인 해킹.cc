#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<vector<int>> v;
int n, m;
int arr[10001], visit[10001];

int dfs(int idx) {
	visit[idx] = 1;
	int sum = 0;
	for (int i = 0; i < v[idx].size(); i++) {
		if (!visit[v[idx][i]])sum += dfs(v[idx][i]);
	}
	return sum + 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		v[b].push_back(a);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		arr[i] = dfs(i);
		ans = max(ans, arr[i]);
		memset(visit, 0, sizeof(visit));
	}
	for (int i = 1; i <= n; i++) {
		if (ans == arr[i])cout << i << " ";
	}
}