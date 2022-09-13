#include <iostream>
using namespace std;
int check[2500], q, u, a, c, k;
string s;

bool t(char c, char i) {
	return (c == 'q' && i == 'u') || (c == 'u' && i == 'a') || (c == 'a' && i == 'c') || (c == 'c' && i == 'k');
}
int main() {
	cin >> s;
	int ans = 0;

	for (int i = 0; i < s.length(); i++) {
		if (check[i])continue;
		
		if (s[i] == 'q') {
			int idx = i;
			check[i] = 1;
			for (int j = i + 1; j < s.length(); j++) {
				if (!check[j] && t(s[idx], s[j])) {
					check[j] = 1;
					idx = j;
				}
			}
		}
	}

	for (int i = 0; i < s.length(); i++) {
		if (!check[i]) {
			cout << -1;
			return 0;
		}
		if (s[i] == 'q')q++;
		if (s[i] == 'u')u++;
		if (s[i] == 'a')a++;
		if (s[i] == 'c')c++;
		if (s[i] == 'k')k++;
	}

	if (q == u && u == a && a == c && c == k) {

		int a = 0;

		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'q')a++;
			if (s[i] == 'k')a--;
			ans = max(ans, a);
		}

		cout << ans;
	}
	else cout << -1;
}