#include <cstring>
#include <iostream>
using namespace std;

int a[5001], dp[5001], n;

int go(int l) {
    
    if (l > n) {
        return dp[l] = 0;
    }
    
    if (dp[l] != 0) {
        return dp[l];
    }

    int ans = -1;

    for (int i = l + 1; i <= n; i += 2) {
        bool ispal = true;
        for (int j = 0; j <= (i - l) / 2; j++) {
            if (a[l + j] != a[i - j]) {
                ispal = false;
                break;
            }
        }
        if (ispal) {
            int res = go(i + 1);
            if (res != -1) {
                ans = max(ans, res + 1);
            }
        }
    }

    return dp[l] = ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ans = go(1);

    cout << (ans ? ans : -1);
}