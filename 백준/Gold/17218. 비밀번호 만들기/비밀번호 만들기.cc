#include <iostream>
#include <algorithm>
using namespace std;

string s1, s2;
int dp[41][41];

int main() {
    cin >> s1 >> s2;
    for (int i = 1; i <= s1.length(); i++) {
        for (int j = 1; j <= s2.length(); j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(max(dp[i - 1][j - 1], dp[i][j - 1]), dp[i - 1][j]);
            }
        }
    }
    int cnt = dp[s1.length()][s2.length()];
    string ans = "";
    int x = s1.length(), y = s2.length();
    while (cnt > 0) {
        while (dp[x - 1][y - 1] == cnt) {
            x--;
            y--;
        }
        while (dp[x - 1][y] == cnt) {
            x--;
        }
        while (dp[x][y - 1] == cnt) {
            y--;
        }
        cnt--;
        ans += s1[x - 1];
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}