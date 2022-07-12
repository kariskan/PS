#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int n, m, s,t;
vector<tuple<int, int, int>> v; //cost, n1, n2
vector<vector<pair<int, int>>> edge;
int parent[10001];
int ans = 0;
int visit[10001];
void go(int idx, int ma) {
	if (idx == t) {
		ans = ma;
		return;
	}
	for (int i = 0; i < edge[idx].size(); i++) {
		if (!visit[edge[idx][i].first]) {
			visit[edge[idx][i].first] = 1;
			go(edge[idx][i].first, min(edge[idx][i].second, ma));
		}
	}
}
bool compare(tuple<int, int, int> t1, tuple<int, int, int> t2) {
	return get<0>(t1) > get<0>(t2);
}
int fp(int x) {
	if (parent[x] == x) return x;
	else return fp(parent[x]);
}
void Union(int a, int b) {
	a = fp(a);
	b = fp(b);
	if (a > b)parent[a] = b;
	else parent[b] = a;
}
int main() {
	cin >> n >> m;
	edge.resize(n + 1);
	for (int i = 1; i <= n; i++)parent[i] = i;
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		v.push_back({ c,a,b });
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++) {
		int cost, n1, n2;
		tie(cost, n1, n2) = v[i];
		if (fp(n1) != fp(n2)) {
			Union(n1, n2);
			edge[n1].push_back({ n2,cost });
			edge[n2].push_back({ n1,cost });
		}
	}
	cin >> s >> t;
	visit[s] = 1;
	go(s, 1000000000);
	cout << ans;
}