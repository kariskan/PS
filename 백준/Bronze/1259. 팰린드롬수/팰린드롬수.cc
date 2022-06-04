#include <iostream>
using namespace std;

int main() {
	while (1) {
		string s;
		cin >> s;
		if (s == "0")break;
		string ans = "yes";
		for (int i = 0; i < s.length(); i++) {
			if (s[i] != s[s.length() - i - 1]) {
				ans = "no";
			}
		}
		cout << ans << "\n";
	}
}