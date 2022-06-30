#include <iostream>
#include <map>
using namespace std;
map<long long, int> m;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long t; cin >> t;
		m[t]++;
	}
	long long ma = 0, ans;
	for (auto& i : m) {
		if (ma < i.second) {
			ma = i.second;
			ans = i.first;
		}
	}
	cout << ans;
}