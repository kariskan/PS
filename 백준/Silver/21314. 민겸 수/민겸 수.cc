#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;

	//max
	string maxAns = "";
	string t = "";
	for (int i = 0; i < s.length(); i++) {
		if (t.empty()) t = "1";
		else t += "0";

		if (s[i] == 'K') {
			if (t.empty()) {
				maxAns += "5";
			}
			else {
				t[0] = '5';
				maxAns += t;
				t = "";
			}
		}
	}
	for (int i = 0; i < t.length(); i++) {
		maxAns += "1";
	}

	string minAns = "";
	t = "";
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'K') {
			if (!t.empty()) {
				minAns += t;
				t = "";
			}
			minAns += "5";
		}
		else {
			if (t.empty()) t = "1";
			else t += "0";
		}
	}
	minAns += t;

	cout << maxAns << '\n' << minAns;
}