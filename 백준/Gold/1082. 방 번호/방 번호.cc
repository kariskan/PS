#include <iostream>
#include <string>
using namespace std;

int a[11], n, m;
string dp[11][51];

string eraseZero(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != '0') {
            return s.substr(i);
        }
    }
    return "0";
}

string maxS(string s1, string s2) {
    string t1 = eraseZero(s1);
    string t2 = eraseZero(s2);

    if (t1.length() > t2.length()) {
        return s1;
    } else if (t1.length() < t2.length()) {
        return s2;
    } else {
        if (t1 > t2) return s1;
        return s2;
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= a[i]) {
                for (int k = 1; k <= i; k++) {
                    dp[i][j] = maxS(dp[i][j], maxS(to_string(i - 1) + dp[k][j - a[i]], dp[k][j - a[i]] + to_string(i - 1)));
                }
            }
        }
    }

    cout << eraseZero(dp[n][m]);
}