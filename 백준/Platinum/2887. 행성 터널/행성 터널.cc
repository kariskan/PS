#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
typedef struct {
	int node;
	long long x;
	long long y;
	long long z;
}p;
int n;
vector<p> v;
bool c1(p p1, p p2) {
	return p1.x < p2.x;
}
bool c2(p p1, p p2) {
	return p1.y < p2.y;
}
bool c3(p p1, p p2) {
	return p1.z < p2.z;
}
int parent[100000];
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
	cin >> n;
	for (int i = 0; i < n; i++) {
		p t;
		cin >> t.x >> t.y >> t.z;
		t.node = i;
		v.push_back(t);
	}
	vector<tuple<long long, int, int>> edge;
	sort(v.begin(), v.end(), c1);
	for (int i = 0; i < n - 1; i++) {
		p p1 = v[i];
		p p2 = v[i + 1];
		long long cost = min(abs(p1.x - p2.x), min(abs(p1.y - p2.y), abs(p1.z - p2.z)));
		edge.push_back({ cost,p1.node,p2.node });
	}
	sort(v.begin(), v.end(), c2);
	for (int i = 0; i < n - 1; i++) {
		p p1 = v[i];
		p p2 = v[i + 1];
		long long cost = min(abs(p1.x - p2.x), min(abs(p1.y - p2.y), abs(p1.z - p2.z)));
		edge.push_back({ cost,p1.node,p2.node });
	}
	sort(v.begin(), v.end(), c3);
	for (int i = 0; i < n - 1; i++) {
		p p1 = v[i];
		p p2 = v[i + 1];
		long long cost = min(abs(p1.x - p2.x), min(abs(p1.y - p2.y), abs(p1.z - p2.z)));
		edge.push_back({ cost,p1.node,p2.node });
	}
	for (int i = 0; i < n; i++)parent[i] = i;
	sort(edge.begin(), edge.end());
	long long ans = 0;
	for (int i = 0; i < edge.size(); i++) {
		int n1, n2;
		long long cost;
		tie(cost, n1, n2) = edge[i];
		if (fp(n1) != fp(n2)) {
			Union(n1, n2);
			ans += cost;
		}
	}
	cout << ans;
}