#include <iostream>
#include <vector>
using namespace std;

int n, m;
string s1, s2;
vector<vector<int>> dp;

bool check(char a, char b) {  // 살려놔야하는 문자인지 확인
    if (a == 'i') {
        return b == 'i' || b == 'j' || b == 'l';
    }
    if (a == 'v') {
        return b == 'v' || b == 'w';
    }
    return a == b;
}

int main() {
    cin >> n >> m >> s1 >> s2;
    dp.resize(n + 1, vector<int>(m + 1));
    int r, ans = 0, r2;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = i;
    }
    for (int j = 1; j <= m; j++) {
        dp[0][j] = j;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (check(s1[i - 1], s2[j - 1])) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
            } else {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
        }
    }

    cout << dp[n][m];

    return 0;
}