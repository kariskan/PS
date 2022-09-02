#include <iostream>
#include <algorithm>
using namespace std;

string dp[251];

string bigAdd(string a, string b) {

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	if (a.length() < b.length())swap(a, b);

	for (int i = 0; i < a.length() - b.length(); i++) {
		b.push_back('0');
	}

	string res = "";
	int div = 0;
	int mod = 0;
	for (int i = 0; i < a.length(); i++) {
		int num = (a[i] - '0') + (b[i] - '0') + div;
		div = num / 10;
		mod = num % 10;
		res.push_back((mod + '0'));
	}

	if (div) res.push_back(div + '0');

	reverse(res.begin(), res.end());

	return res;
}

int main() {

	dp[0] = "1";
	dp[1] = "1";
	dp[2] = "3";
	dp[3] = "5";

	for (int i = 4; i <= 250; i++) {
		dp[i] = bigAdd(bigAdd(dp[i - 2], dp[i - 2]), dp[i - 1]);
	}
	int n;
	while (cin >> n) {
		cout << dp[n] << '\n';
	}
}