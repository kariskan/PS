#include <iostream>
using namespace std;

int n;
string s;

void go() {
	cout << "Good\n";
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;

		int idx = 0;

		if (!(s[0] >= 'A' && s[0] <= 'F')) {
			go();
			continue;
		}

		if (s[0] >= 'B' && s[0] <= 'F') {
			idx = 1;
		}

		int t = idx;

		while (s[idx] == 'A' && idx < s.length()) idx++;

		if (idx == t || idx == s.length()) {
			go();
			continue;
		}

		t = idx;

		while (s[idx] == 'F' && idx < s.length()) idx++;

		if (idx == t || idx == s.length()) {
			go();
			continue;
		}

		t = idx;

		while (s[idx] == 'C' && idx < s.length()) idx++;

		if (idx == t) {
			go();
			continue;
		}

		if (idx != s.length()) {
			if (!(s[idx] >= 'A' && s[idx] <= 'F')) {
				go();
				continue;
			}
		}

		cout << "Infected!\n";
	}
}