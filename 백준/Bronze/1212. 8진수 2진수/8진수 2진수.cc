#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

string toBinary(int a) {
	string res = "";
	while (a) {
		res += to_string(a % 2);
		a /= 2;
	}
	return res;
}

string go(string s) {
	reverse(s.begin(), s.end());
	string res = "";
	for (int i = 0; i < s.length(); i++) {
		string t = toBinary(s[i] - '0');
		int k = 3 * i - 1;
		for (int j = res.length(); j <= k; j++) {
			res += "0";
		}
		res += t;
	}
	reverse(res.begin(), res.end());
	return res;
}


int main() {
	string s;
	cin >> s;
	if (s == "0")cout << 0;
	else cout << go(s);
}