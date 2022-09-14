#include <iostream>
using namespace std;

string s;

char mo[5] = { 'a','e','i','o','u' };
int m[26];

bool check1() {
	for (int i = 0; i < 5; i++) {
		if (s.find(mo[i]) != string::npos) return true;
	}
	return false;
}

bool check2() {
	if (s.length() < 3) return true;
	for (int i = 0; i <= s.length() - 3; i++) {
		if (m[s[i] - 'a'] && m[s[i + 1] - 'a'] && m[s[i + 2] - 'a']) return false;
		if (!m[s[i] - 'a'] && !m[s[i + 1] - 'a'] && !m[s[i + 2] - 'a']) return false;
	}

	return true;
}

bool check3() {
	if (s.length() < 2) return true;
	for (int i = 0; i <= s.length() - 2; i++) {
		if (s[i] == 'e' && s[i + 1] == 'e')continue;
		if (s[i] == 'o' && s[i + 1] == 'o')continue;
		if (s[i] == s[i + 1]) return false;
	}
	return true;
}

int main() {
	m[0] = m[4] = m[14] = m[8] = m[20] = 1;
	while (cin >> s, s != "end") {
		if (check1() && check2() && check3()) cout << "<" << s << "> is acceptable.\n";
		else cout << "<" << s << "> is not acceptable.\n";
	}
}