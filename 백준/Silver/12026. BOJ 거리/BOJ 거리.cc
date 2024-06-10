#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <set>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> dp(n, INT_MAX);
    string s;
    cin >> s;
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if ((s[j] == 'B' && s[i] == 'O' && dp[j] != INT_MAX) || (s[j] == 'O' && s[i] == 'J' && dp[j] != INT_MAX) ||
                (s[j] == 'J' && s[i] == 'B' && dp[j] != INT_MAX)) {
                dp[i] = min(dp[i], dp[j] + (j - i) * (j - i));
            }
        }
    }
    cout << (dp[n - 1] == INT_MAX ? -1 : dp[n - 1]);
}