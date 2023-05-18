#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int n, dp[201][201];
string s1, s2, s3;

int main() {
    cin >> n;
    for (int tc = 1; tc <= n; tc++) {
        memset(dp, 0, sizeof(dp));
        cin >> s1 >> s2 >> s3;

        dp[0][0] = 1;
        for (int i = 1; i <= s1.length(); i++) {
            if (s1[i - 1] == s3[i - 1]) {
                dp[i][0] = dp[i - 1][0];
            } else {
                dp[i][0] = 0;
            }
        }
        for (int i = 1; i <= s2.length(); i++) {
            if (s2[i - 1] == s3[i - 1]) {
                dp[0][i] = dp[0][i - 1];
            } else {
                dp[0][i] = 0;
            }
        }

        for (int i = 1; i <= s1.length(); i++) {
            for (int j = 1; j <= s2.length(); j++) {
                if (s1[i - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
                if (s2[j - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
                }
            }
        }

        cout << "Data set " << tc << ": ";
        if (!dp[s1.length()][s2.length()]) {
            cout << "no\n";
        } else {
            cout << "yes\n";
        }
    }
}