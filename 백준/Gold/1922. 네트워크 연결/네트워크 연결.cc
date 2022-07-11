#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int parent[1001];
int fp(int x) {
	if (parent[x] == x)return x;
	else return fp(parent[x]);
}
void Union(int a, int b) {
	a = fp(a);
	b = fp(b);
	if (a > b)parent[a] = b;
	else parent[b] = a;
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)parent[i] = i;
	vector<pair<int, pair<int, int>>> v;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ c,{a,b} });
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (int i = 0; i < m; i++) {
		if (fp(v[i].second.first) != fp(v[i].second.second)) {
			Union(v[i].second.first, v[i].second.second);
			ans += v[i].first;
		}
	}
	cout << ans;
}