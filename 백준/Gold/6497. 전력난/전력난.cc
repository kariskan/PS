#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int parent[200000];
int n, m;
int find(int x) {
	if (parent[x] == x)return x;
	else return(find(parent[x]));
}
void Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a > b)parent[a] = b;
	else parent[b] = a;
}
int main() {
	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0)break;
		vector<pair<int, pair<int, int>>> v;
		int sum = 0;
		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			v.push_back({ c,{a,b} });
			sum += c;
		}
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
		sort(v.begin(), v.end());
		for (auto& i : v) {
			if (find(i.second.first) != find(i.second.second)) {
				Union(i.second.first, i.second.second);
				sum -= i.first;
			}
		}
		cout << sum << '\n';
	}
}