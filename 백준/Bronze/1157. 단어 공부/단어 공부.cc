#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	int a[27] = { 0, };
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z')a[s[i] - 'a']++;
		else a[s[i] - 'A']++;
	}
	int max = 0, cnt = 0;
	for (int i = 0; i < 27; i++) {
		if (a[max] < a[i]) {
			max = i;
			cnt = 1;
		}
		else if (a[max] == a[i])cnt++;
	}
	if (cnt > 1)cout << "?";
	else cout << (char)(max + 'A');
}