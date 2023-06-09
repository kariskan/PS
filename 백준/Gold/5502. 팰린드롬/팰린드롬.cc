#include <algorithm>
#include <iostream>
using namespace std;

int dp[5001][5001];

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string rev = s;
    reverse(rev.begin(), rev.end());

    for (int i = 1; i <= s.length(); i++) {
        for (int j = 1; j <= rev.length(); j++) {
            if (s[i - 1] == rev[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    cout << n - dp[n][n];
}