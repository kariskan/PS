#include <iostream>
#include <string>
#include <set>
using namespace std;

string s;
int ans;
set<string> se;

void go(string res, string k, int left, int right) {
	if (k.length() == s.length()) {
		if (se.find(res) == se.end()) {
			ans++;
			se.insert(res);
		}
		return;
	}

	if (left > 0) {
		string t = s[left - 1] + k;
		go(res + t, t, left - 1, right);
	}
	if (right < s.length() - 1) {
		string t = k + s[right + 1];
		go(res + t, t, left, right + 1);
	}
}

int main() {
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		string t(1, s[i]);
		go(t, t, i, i);
	}

	cout << ans;
}