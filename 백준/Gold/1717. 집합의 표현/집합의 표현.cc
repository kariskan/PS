#include <iostream>
using namespace std;
int set[1000001];
int find(int x) {
	if (x == set[x])return x;
	else return set[x] = find(set[x]);
}
void uni(int x, int y) {
	x = find(x);
	y = find(y);
	if (x > y) set[x] = y;
	else set[y] = x;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		set[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a) {
			if (find(b) == find(c)) {
				cout << "YES\n";
			}
			else cout << "NO\n";
		}
		else {
			uni(b, c);
		}
	}
}