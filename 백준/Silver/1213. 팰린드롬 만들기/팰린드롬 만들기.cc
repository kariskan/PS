#include <iostream>
using namespace std;

string s;
int cnt[26];
int main() {
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		cnt[s[i] - 'A']++;
	}
	int hol = 0;
	for (int i = 0; i < 26; i++) {
		if (cnt[i] % 2 != 0)hol++;
	}
	if (hol > 1)cout << "I'm Sorry Hansoo";
	else {
		string ans = "";
		int last = -1;
		for (int i = 0; i < 26; i++) {
			if (!cnt[i])continue;
			if (cnt[i] % 2 != 0) {
				last = i;
				cnt[i]--;
			}
			for (int j = 0; j < cnt[i] / 2; j++) {
				ans += (i + 'A');
			}
		}
		if (last != -1) {
			ans += (last + 'A');
		}
		for (int i = hol ? ans.length() - 2 : ans.length() - 1; i >= 0; i--) {
			ans += ans[i];
		}
		cout << ans;
	}
}