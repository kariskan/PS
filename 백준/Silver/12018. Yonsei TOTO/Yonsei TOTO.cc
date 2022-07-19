#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int p, l;
		cin >> p >> l;
		vector<int> v2;
		for (int j = 0; j < p; j++) {
			int num; cin >> num;
			v2.push_back(num);
		}
		sort(v2.begin(), v2.end());
		if (v2.size() < l)v.push_back(1);
		else v.push_back(v2[v2.size() - l]);
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (auto i : v) {
		if (i <= m) {
			m -= i;
			ans++;
		}
	}
	cout << ans;
}
