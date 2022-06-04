#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int a[26];
	memset(a, -1, sizeof(a));
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (a[s[i] - 'a'] == -1)a[s[i] - 'a'] = i;
	}
	for (int i = 0; i < 26; i++) {
		cout << a[i] << " ";
	}
}