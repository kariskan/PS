#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	int ans = 0;
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] == s2[0] && s1.substr(i, s2.length()) == s2) {
			ans++;
			i += s2.length() - 1;
		}
	}
	cout << ans;
}