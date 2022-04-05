#include <iostream>
using namespace std;

int fail[1000000];
int main() {
	int n;
	string s;
	cin >> n >> s;
	int len = s.length();
	int j = 0;
	for (int i = 1; i < len; i++) {
		while (j > 0 && s[i] != s[j])j = fail[j - 1];
		if (s[i] == s[j]) {
			fail[i] = j + 1;
			j++;
		}
		else {
			fail[i] = 0;
		}
	}
	cout << n - fail[n - 1];
}