#include <iostream>
using namespace std;

int n;
string pat;

int main() {
	cin >> n >> pat;
	string start = "", end = "";
	for (int i = 0; i < pat.length(); i++) {
		if (pat[i] == '*') {
			end = pat.substr(i + 1);
			break;
		}
		start += pat[i];
	}
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s.length() >= start.length() + end.length() &&
			start == s.substr(0, start.length()) && end == s.substr(s.length() - end.length())) {
			cout << "DA\n";
		}
		else cout << "NE\n";
	}
}