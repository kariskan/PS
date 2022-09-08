#include <iostream>
using namespace std;

int get(string s, char c, int n) {

	int ans = 1;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			if (s[i] == c) {
				continue;
			}
			else {
				ans++;
			}
		}
		else {
			if (s[i] == s[i - 1])continue;
			if (s[i] != c) ans++;
		}
	}
	return ans;
}

int main() {
	int n; cin >> n;
	string s; cin >> s;
	int ans = 1;
	for (int i = 1; i < n; i++) {
		if (s[i] != s[i - 1])ans++;
	}
	cout << min(min(ans, get(s, 'B', n)), get(s, 'R', n));
}