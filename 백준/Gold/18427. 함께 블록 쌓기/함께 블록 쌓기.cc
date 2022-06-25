#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, m, h;
int dp[51][1001];
vector<int> v[51];

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie();
	cin >> n >> m >> h;
	cin.ignore(1);
	for (int i = 1; i <= n; i++) {
		string s;
		getline(cin, s);
		int temp = 0;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == ' ') {
				v[i].push_back(temp);
				temp = 0;
			}
			else {
				temp = temp * 10 + (s[j] - '0');
			}
		}
		if (temp != 0)v[i].push_back(temp);
	}
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = 1;
		for (int j = 1; j <= h; j++) {
			dp[i][j] = dp[i - 1][j];
			for (int k = 0; k < v[i].size(); k++) {
				if (j < v[i][k])continue;
				dp[i][j] = (dp[i][j] % 10007 + dp[i - 1][j - v[i][k]] % 10007) % 10007;
			}
		}
	}
	cout << dp[n][h] % 10007;
}