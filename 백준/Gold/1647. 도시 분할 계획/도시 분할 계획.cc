#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, pair<int, int>>> v; //cost, a, b
int n, m, parent[100001];

int getParent(int a) {
	if (parent[a] == a)return a;
	else return parent[a] = getParent(parent[a]);
}

void Union(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a > b)parent[a] = b;
	else parent[b] = a;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)parent[i] = i;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ c,{a,b} });
	}
	sort(v.begin(), v.end());
	int ans = 0, max = 0;
	for (int i = 0; i < m; i++) {
		if (getParent(v[i].second.first) != getParent(v[i].second.second)) {
			Union(v[i].second.first, v[i].second.second);
			ans += v[i].first;
			if (max < v[i].first)max = v[i].first;
		}
	}
	cout << ans - max;
}