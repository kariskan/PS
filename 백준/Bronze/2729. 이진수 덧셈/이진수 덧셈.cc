#include <iostream>
#include <algorithm>
using namespace std;

int n;

string go(string s1, string s2) {
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());

	if (s1.length() > s2.length()) swap(s1, s2);

	while(s2.length() != s1.length()) s1 += "0";

	string res = "";
	string p = "0";
	for (int i = 0; i < s1.length(); i++) {
		int cnt = 0;
		if (s1[i] == '1') cnt++;
		if (s2[i] == '1') cnt++;
		if (p == "1") cnt++;

		if (cnt == 0) res += "0";
		else if (cnt == 1) {
			res += "1";
			p = "0";
		}
		else if (cnt == 2) {
			res += "0";
			p = "1";
		}
		else {
			res += "1";
			p = "1";
		}
	}

	if (p == "1") res += "1";

	for (int i = res.length() - 1; i > 0; i--) {
		if (res[i] == '0') {
			res.pop_back();
		}
		else break;
	}

	reverse(res.begin(), res.end());

	return res;
}

int main() {
	cin >> n;
	string s1, s2;

	for (int i = 0; i < n; i++) {
		cin >> s1 >> s2;
		cout << go(s1, s2) << '\n';
	}
}