#include <iostream>
using namespace std;

int main() {
	while (1) {
		string s1, s2;
		cin >> s1;
		if (cin.eof()) break;
		cin >> s2;

		int idx = 0;
		for (int i = 0; i < s2.length(); i++) {
			if (s2[i] == s1[idx]) {
				idx++;
			}
			if (idx == s1.length()) break;
		}
		if (idx == s1.length()) {
			cout << "Yes\n";
		}
		else cout << "No\n";
	}
}