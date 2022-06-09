#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
vector<tuple<int, int, int>> edge;
int parent[10001];

int findP(int a) {
	if (parent[a] == a)return a;
	else return parent[a] = findP(parent[a]);
}

void uni(int a, int b) {
	int pa = findP(a);
	int pb = findP(b);
	if (pa != pb)parent[pb] = pa;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int v, e;
	cin >> v >> e;
	for (int i = 1; i <= v; i++)parent[i] = i;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge.push_back({ c,a,b });
	}
	sort(edge.begin(), edge.end());
	long long ans = 0;
	for (int i = 0; i < e; i++) {
		int a, b, c; //w, v1, v2
		tie(a, b, c) = edge[i];
		if (findP(b) == findP(c)) {
			continue;
		}
		else {
			ans += a;
			uni(b, c);
		}
	}
	cout << ans;
}