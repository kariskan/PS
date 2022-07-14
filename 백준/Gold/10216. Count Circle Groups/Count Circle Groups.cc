#include <iostream>
#include <map>
#include <cstring>
using namespace std;
int parent[3000];
int inp[3000][3];
map<int, int> ma;
bool ok(int x1, int y1, int r1, int x2, int y2, int r2) {
	return (r1 + r2) * (r1 + r2) >= (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
int f(int x) {
	if (parent[x] == x)return x;
	return f(parent[x]);
}
void Union(int a, int b) {
	a = f(a);
	b = f(b);
	if (a > b)parent[a] = b;
	else parent[b] = a;
}
int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			int x, y, r;
			cin >> x >> y >> r;
			inp[i][0] = x;
			inp[i][1] = y;
			inp[i][2] = r;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i != j && ok(inp[i][0],inp[i][1],inp[i][2],inp[j][0],inp[j][1],inp[j][2])) {
					Union(i, j);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			ma[f(i)]++;
		}
		cout << ma.size() << '\n';
		ma.clear();
		memset(parent, 0, sizeof(parent));
	}
}