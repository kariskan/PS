#include <iostream>
#include <vector>
using namespace std;
int n, m;
int parent[500001];
vector<pair<int, int>> v;
int getParent(int x) {
	if (parent[x] == x) return x;
	else return parent[x] = getParent(parent[x]);
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
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	for (int i = 0; i < m; i++) {
		int a = v[i].first;
		int b = v[i].second;
		a = getParent(a);
		b = getParent(b);
		if (a == b) {
			cout << i + 1;
			return 0;
		}
		else {
			Union(a, b);
		}
	}
	cout << 0;
}