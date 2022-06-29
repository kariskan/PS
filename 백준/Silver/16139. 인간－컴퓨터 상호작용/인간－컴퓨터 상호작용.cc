#include <iostream>
using namespace std;
string s;
int cnt[200000][26];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	int q;
	cin >> q;
	for (int i = 0; i < s.length(); i++) {
		cnt[i][s[i] - '0' - 49]++;
		for (int j = 0; j < 26; j++) {
			if (!i)continue;
			cnt[i][j] += cnt[i - 1][j];
		}
	}
	for (int i = 0; i < q; i++) {
		char c; int l, r;
		cin >> c >> l >> r;
		int sum = cnt[r][c - '0' - 49];
		if (l)sum -= cnt[l - 1][c - '0' - 49];
		cout << sum << '\n';
	}
}