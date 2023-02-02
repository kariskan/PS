#include <iostream>
using namespace std;

int n;

bool bad(string s) {
	for (int i = 2; i <= s.length(); i += 2) {
		for (int j = 0; j <= s.length() - i; j++) {
			string s1 = s.substr(j, i / 2);
			string s2 = s.substr(j + i / 2, i / 2);
			if (s1 == s2)return true;
		}
	}
	return false;
}

void go(string s) {
	if (s.length() == n) {
		cout << s;
		exit(0);
	}

	if (!bad(s + "1")) {
		go(s + "1");
	}
	if (!bad(s + "2")) {
		go(s + "2");
	}
	if (!bad(s + "3")) {
		go(s + "3");
	}
}

int main() {
	cin >> n;
	go("");
}