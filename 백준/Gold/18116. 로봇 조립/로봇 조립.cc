#include <iostream>
using namespace std;

int parent[1000001], cnt[1000001];

int Find(int a) {
	if (parent[a] == a) return a;
	return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	if (a != b) {
		parent[b] = a;
		cnt[a] += cnt[b];
	}
}

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
	int n; cin >> n;

	for (int i = 1; i <= 1000000; i++) {
		parent[i] = i;
		cnt[i] = 1;
	}

	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		if (c == 'I') {
			int a, b; cin >> a >> b;
			Union(a, b);
		}
		else {
			int a; cin >> a;
			cout << cnt[Find(a)] << '\n';
		}
	}
}