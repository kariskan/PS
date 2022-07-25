#include <iostream>
#include <cstring>
using namespace std;

int parent[10001], t, visit[10001];

int main() {
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i < n; i++) {
			int a, b; cin >> a >> b;
			parent[b] = a;
		}
		int root;
		for (int i = 1; i <= n; i++) {
			if (parent[i] == 0)root = i;
		}
		int a, b; cin >> a >> b;
		while (a != 0) {
			visit[a] = 1;
			a = parent[a];
		}
		while (b != 0) {
			if (visit[b]) {
				cout << b << '\n';
				break;
			}
			b = parent[b];
		}
		memset(visit, 0, sizeof(visit));
		memset(parent, 0, sizeof(parent));
	}
}