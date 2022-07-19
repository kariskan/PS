#include <iostream>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s1, s2;
		cin >> s1 >> s2;
		int w = 0, w2 = 0;
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] == 'W')w++;
			if (s2[i] == 'W')w2++;
		}
		if (w == w2) {
			int cnt = 0;
			for (int i = 0; i < s1.length(); i++) {
				if (s1[i] != s2[i])cnt++;
			}
			cout << cnt / 2 << '\n';
		}
		else {
			int cnt = 0;
			for (int i = 0; i < s1.length(); i++) {
				if (s1[i] == 'W' && s2[i] == 'W') {
					cnt++;
				}
			}
			w -= cnt;
			w2 -= cnt;
			cout << min(w, w2) + max(w, w2) - min(w, w2) << '\n';
		}
	}
}