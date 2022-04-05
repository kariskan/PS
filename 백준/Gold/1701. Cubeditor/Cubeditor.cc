#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> fail;
int main() {
	string s;
	cin >> s;
	int len = s.length();
	int j = 0;
	int ans = 0;
	reverse(s.begin(), s.end());
	string a = "";
	for (int i = 0; i < len; i++) {
		fail.resize(len);
		a = s[i] + a;
		j = 0;
		int aLen = a.length();
		for (int k = 1; k < aLen; k++) {
			while (j > 0 && a[j] != a[k]) {
				j = fail[j - 1];
			}
			if (a[j] == a[k]) {
				fail[k] = ++j;
			}
			else {
				fail[k] = 0;
			}
			ans = max(ans, fail[k]);
		}
		fail.clear();
	}
	cout << ans;
}