#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n, m;
string multiple(string s1, string s2) {
	string res = "";
	int cnt[500] = { 0, };
	int idx = 0;
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	for (int j = 0; j < s2.length(); j++) {
		for (int i = 0; i < s1.length(); i++) {
			int mul = (s1[i] - '0') * (s2[j] - '0');
			cnt[i + j] += mul;
		}
	}
	int i = 0;
	int maxTi = 0;
	for (int i = 0; i < s1.length() + s2.length() - 1; i++) {
		int ti = i;
		while (cnt[ti] >= 10) {
			cnt[ti + 1] += cnt[ti] / 10;
			cnt[ti] = cnt[ti] % 10;
			ti++;
		}
		maxTi = max(ti, maxTi);
	}
	for (int i = maxTi; i >= 0; i--)res += (cnt[i] + '0');
	return res;
}
string divide(string s1, int s2) {
	int cnt[500] = { 0, };
	for (int i = 0; i < s1.length(); i++) {
		cnt[i] = s1[i] - '0';
	}
	int len = s1.length();
	string res = "";
	int ti = 0;
	while (cnt[ti] == 0) {
		ti++;
	}
	for (int i = ti; i < len; i++) {
		if (cnt[i] % s2 == 0) {
			cnt[i] = cnt[i] /= s2;
		}
		else {
			cnt[i + 1] += 10 * (cnt[i] % s2);
			cnt[i] = cnt[i] /= s2;
		}
		res += (cnt[i] + '0');
	}
	return res;
}
string solve(int n, int m) {
	if (m >= n / 2)m = n - m;
	string res = to_string(n);
	for (int i = n - 1; i > n - m; i--) {
		res = multiple(res, to_string(i));
	}

	for (int i = 2; i <= m; i++) {
		res = divide(res, i);
	}
	for (int i = 0; i < res.length(); i++) {
		if (res[i] != '0')break;
		res.erase(res.begin());
		i--;
	}
	return res;
}

int main() {
	cin >> n >> m;

	cout << solve(n, m);
}