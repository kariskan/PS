#include <iostream>
using namespace std;

string s1, s2;

int main() {
	cin >> s1 >> s2;
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] >= '0' && s1[i] <= '9') {
			s1.erase(s1.begin() + i);
			i--;
		}
	}
	for (int i = 0; i < s1.length() - s2.length() + 1; i++) {
		if (s1[i] == s2[0]) {
			int ok = 1;
			for (int j = 0; j < s2.length() && i + j < s1.length(); j++) {
				if (s1[i + j] != s2[j]) {
					ok = 0; break;
				}
			}
			if (ok) {
				cout << 1;
				return 0;
			}
		}
	}
	cout << 0;
}