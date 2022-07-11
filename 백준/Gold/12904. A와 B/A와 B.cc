#include <iostream>
#include <algorithm>
using namespace std;
string s1, s2;
int go() {
	while (1) {
		if (s1.length() == s2.length()) {
			if (s1 == s2) {
				return 1;
			}
			else return 0;
		}
		if (s2[s2.length() - 1] == 'A') {
			s2.pop_back();
		}
		else {
			s2.pop_back();
			reverse(s2.begin(), s2.end());
		}
	}
}
int main() {
	
	cin >> s1 >> s2;
	cout << go();
}