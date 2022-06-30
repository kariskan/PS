#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	string a = "";
	for (int i = 1; i <= 999; i++) {
		a = "";
		for (int j = i;; j++) {
			a += to_string(j);
			if (a.length() == s.length() && a == s) {
				cout << i << ' ' << j;
				return 0;
			}
			if (a.length() > s.length()) {
				break;
			}
		}
	}
}