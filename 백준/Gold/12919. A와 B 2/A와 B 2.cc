#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s, t;
bool ok = false;

void go(string c) {
	if (c.length() < s.length()) return;
	if (c == s) {
		ok = true;
		return;
	}

	if (c.front() == 'B') {
		string temp = c.substr(1);
		reverse(temp.begin(), temp.end());
		go(temp);
		if (ok)return;
	}

	if (c.back() == 'A') {
		c.pop_back();
		go(c);
	}
}

int main() {
	cin >> s >> t;
	go(t);

	cout << ok ? 1 : 0;
}