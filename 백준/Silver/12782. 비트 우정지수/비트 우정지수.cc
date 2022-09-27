#include <iostream>
#include <cstring>
using namespace std;

int t, a[1000001], b[1000001];
string s1, s2;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;

	while (t--) {
		cin >> s1 >> s2;

		int s1c = 0, s2c = 0, cnt = 0;

		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] == '0') s1c++;
			if (s2[i] == '0') s2c++;
		}

		int ans = abs(s1c - s2c);

		for (int i = 0; i < s1.length(); i++) {
			if (ans == 0) break;
			if (s1c > s2c) {
				if (s1[i] == '0' && s2[i] == '1') {
					s2[i] = '0';
					ans--;
				}
			}
			else {
				if (s1[i] == '1' && s2[i] == '0') {
					s1[i] = '0';
					ans--;
				}
			}
		}

		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] != s2[i]) ans++;
		}

		cout << ans / 2 + abs(s1c - s2c) << '\n';
	}
}