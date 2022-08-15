#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s[10001];

string sum(string s1, string s2) {

	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());

	int dif = s1.length() - s2.size();
	if (dif < 0)dif = -dif;

	for (int i = 0; i < dif; i++) {
		if (s1.length() > s2.length()) s2 += '0';
		else s1 += '0';
	}

	string ret = "";
	int temp = 0;
	
	for (int i = 0; i < s1.length(); i++) {
		int t = (s1[i] - '0' + s2[i] - '0' + temp);
		ret += to_string(t % 10);
		temp = t / 10;
	}

	if (temp != 0) {
		ret += to_string(temp);
	}

	reverse(ret.begin(), ret.end());

	return ret;
}

int main() {
	int a;
	cin >> a;
	s[0] = "0";
	s[1] = "1";

	for (int i = 2; i <= a; i++) {
		s[i] = sum(s[i - 1], s[i - 2]);
	}

	cout << s[a];
}