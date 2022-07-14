#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
int money[10001], parent[10001], ans[10001], visit[10001];
vector<vector<int>> v;
int f(int x) {
	if (parent[x] == x)return x;
	return f(parent[x]);
}
void Union(int a, int b) {
	a = f(a);
	b = f(b);
	int p;
	if (money[a] > money[b]) {
		parent[a] = b;
	}
	else parent[b] = a;
}
int main() {
	cin >> n >> m >> k;
	v.resize(n + 1);
	for (int i = 1; i <= n; i++)parent[i] = i;
	for (int i = 1; i <= n; i++)cin >> money[i];
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		if (f(a) != f(b)) {
			Union(a, b);
		}
	}
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		int p = f(i);
		if (!visit[p]) {
			visit[p] = 1;
			answer += money[p];
		}
	}
	if (answer <= k) cout << answer;
	else cout << "Oh no";
}