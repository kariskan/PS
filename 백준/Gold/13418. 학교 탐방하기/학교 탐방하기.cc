#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

bool b(tuple<int, int, int>& t1, tuple<int, int, int>& t2) { //오르막길 먼저
	return get<2>(t1) < get<2>(t2);
}

bool s(tuple<int, int, int>& t1, tuple<int, int, int>& t2) {
	return get<2>(t1) > get<2>(t2);
}

int parent[1001];

int find(int a) {
	if (a == parent[a]) return a;
	else return find(parent[a]);
}

void Union(int a, int b) {
	a = find(a);
	b = find(b);

	parent[a] = b;
}

int get(vector<tuple<int, int, int>> v) {

	int res = 0;

	for (int i = 0; i < v.size(); i++) {
		int a, b, c;
		tie(a, b, c) = v[i];
		if (find(a) != find(b)) {
			if (c == 0)res++;
			Union(a, b);
		}
	}

	return res * res;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<tuple<int, int, int>> v;
	vector<tuple<int, int, int>> v2;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m + 1; i++) {
		int a, b, c; cin >> a >> b >> c; //c == 0이 오르막길
		v.push_back({ a,b,c });
		v2.push_back({ a,b,c });
	}

	sort(v.begin(), v.end(), b); //오르막길
	sort(v2.begin(), v2.end(), s);

	int a = get(v);
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}
	
	cout << a - get(v2);
}