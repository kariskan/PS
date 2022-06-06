#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define mod 1000000007
typedef vector<vector<long long>> vvi;
map<long long, vvi> m;
long long n;

vvi t = { {0,1},{1,1} };
vvi calc(vvi v1, vvi v2) {
	vvi res(2, vector<long long>(2));
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				res[i][j] = (res[i][j] % mod + v1[i][k] % mod * v2[k][j] % mod) % mod;
			}
		}
	}
	return res;
}
vvi run(long long num) {
	if (num == 1)return t;
	vvi t1, t2;
	if (m.find(num / 2) == m.end()) {
		t1 = run(num / 2);
		m.insert({ num / 2,t1 });
	}
	else {
		t1 = m[num / 2];
	}
	if (m.find(num - num / 2) == m.end()) {
		t2 = run(num - num / 2);
		m.insert({ num - num / 2,t2 });
	}
	else {
		t2 = m[num - num / 2];
	}
	return calc(t1, t2);
}
int main() {
	cin >> n;
	cout << run(n)[0][1];
}