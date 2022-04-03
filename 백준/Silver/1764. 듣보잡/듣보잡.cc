#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main() {
	int n, m;
	map<string, int> ma;
	vector<string> v;
	int ans = 0;
	cin >> n >> m;
	for (int i = 0; i < n + m; i++) {
		string s;
		cin >> s;
		ma[s]++;
	}
	for (auto i = ma.begin(); i != ma.end(); i++) {
		if (i->second == 2) {
			ans++;
			v.push_back(i->first);
		}
	}
	sort(v.begin(), v.end());
	cout << ans << "\n";
	for (string s : v) {
		cout << s << "\n";
	}
}