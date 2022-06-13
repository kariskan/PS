#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, c;
int parent[2001];
vector<pair<int, int>> inp;
vector<pair<int, pair<int, int>>> v;
int getDis(int x1, int y1, int x2, int y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
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
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		inp.push_back({ a,b });
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int dis = getDis(inp[i].first, inp[i].second, inp[j].first, inp[j].second);
			if (dis >= c) {
				v.push_back({ dis,{i,j} });
			}
		}
	}
	sort(v.begin(), v.end());
	long long ans = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++)parent[i] = i;
	for (int i = 0; i < v.size(); i++) {
		int cost = v[i].first;
		if (getParent(v[i].second.first) != getParent(v[i].second.second)) {
			ans += cost;
			Union(v[i].second.first, v[i].second.second);
			cnt++;
		}
	}
	if (cnt != n - 1)ans = -1;
	cout << ans;
}