#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
map<string, int> m;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		string t = "";
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == '.') {
				t = s.substr(j + 1);
				m[t]++;
				break;
			}
		}
	}
	for (auto& i : m) {
		cout << i.first << ' ' << i.second << '\n';
	}
}