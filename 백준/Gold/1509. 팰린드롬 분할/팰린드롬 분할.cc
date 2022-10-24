#include <iostream>
#include <cstring>
using namespace std;
int dp[2501][2501], dp2[2501], len;
string s;
int run(int start, int end) {
	if (start == end)return 1;
	if (start == end - 1)return s[start] == s[end];

	int &m1 = dp[start][end];
	if (m1 != -1)return m1;
	return m1 = (s[start] == s[end]) && run(start + 1, end - 1);
}

 int run2(int i) {
	if (i == len)return 0;
	int &res = dp2[i];
	if (res != -1)return res;
	res = 987654321;
	for (int j = i; j < len; j++) {
		if (run(i, j)) {
			res = min(res, 1 + run2(j + 1));
		}
	}
	return res;
}

int main() {
	cin >> s;
	memset(dp, -1, sizeof(dp));
	memset(dp2, -1, sizeof(dp2));
	len = s.length();
	cout<<run2(0);
}