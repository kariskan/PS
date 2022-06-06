#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define mod 1000
typedef vector<vector<int>> vvi;
int n;
long long b;
map<long long, vvi> m;

vvi t;
vvi calc(vvi t1, vvi t2) {
	vvi res(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				res[i][j] = (res[i][j] % mod + (t1[i][k] % mod) * (t2[k][j] % mod)) % mod;
			}
		}
	}
	return res;
}
vvi run(vvi v, long long num) {
	if (num == 1)return t;
	vvi t1, t2;
	if (m.find(num / 2) == m.end()) {
		t1 = run(v, num / 2);
		m.insert({ num / 2, t1 });
	}
	else t1 = m[num / 2];
	if (m.find(num - num / 2) == m.end()) {
		t2 = run(v, num - num / 2);
		m.insert({ num - num / 2, t2 });
	}
	else t2 = m[num - num / 2];
	return calc(t1, t2);
}
int main() {
	cin >> n >> b;
	t.resize(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a; cin >> a;
			t[i].push_back(a);
		}
	}
	t = run(t, b);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << t[i][j] % mod << " ";
		}
		cout << "\n";
	}
}