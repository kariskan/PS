#include <iostream>
#include <map>
using namespace std;
int parent[200001];
int Size[200001];
int id = 1;
map<string, int> m;
int f(int x) {
	if (parent[x] == x)return x;
	else return f(parent[x]);
}
void Union(int a, int b) {
	a = f(a);
	b = f(b);
	if (Size[a] < Size[b]) {
		swap(a, b);
	}
	Size[a] += Size[b];
	Size[b] = Size[a];
	parent[b] = a;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= 200000; i++) {
			parent[i] = i;
			Size[i] = 1;
		}
		for (int i = 1; i <= n; i++) {
			string a, b;
			cin >> a >> b;
			if (m.count(a) == 0) {
				m[a] = id++;
			}
			if (m.count(b) == 0) {
				m[b] = id++;
			}
			if (f(m[a]) != f(m[b])) {
				Union(m[a], m[b]);
			}
			cout << Size[f(m[a])] << '\n';
		}
		m.clear();
		id = 1;
	}
}