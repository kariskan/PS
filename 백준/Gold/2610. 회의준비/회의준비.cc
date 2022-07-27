#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<int>> v;
int parent[101];
int find(int a) {
	if (parent[a] == a)return a;
	else return find(parent[a]);
}
void Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a > b) parent[a] = b;
	else parent[b] = a;
}
int parentVisit[101];
int main() {
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 1; i <= n; i++)parent[i] = i;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		if (find(a) != find(b)) {
			Union(a, b);
		}
	}
	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		int f = find(i);
		if (!parentVisit[f]) {
			parentVisit[f] = 1;
			int cnt = 1000000;
			int a = i;
			for (int j = 1; j <= n; j++) {
				if (find(j) == f) {
					int visit[101] = { 0, };
					queue<int> q;
					q.push(j);
					visit[j] = 1;
					int t = 0;
					while (!q.empty()) {
						int k = q.front();
						q.pop();

						t = max(t, visit[k] - 1);

						for (auto& i : v[k]) {
							if (!visit[i]) {
								visit[i] = visit[k] + 1;
								q.push(i);
							}
						}
					}
					if (cnt > t) {
						cnt = t;
						a = j;
					}
				}
			}
			ans.push_back(a);
		}
	}
    sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (auto& i : ans)cout << i << '\n';
}