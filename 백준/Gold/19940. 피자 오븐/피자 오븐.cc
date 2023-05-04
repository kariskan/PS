#include <iostream>
#include <queue>
using namespace std;

int d[5] = {60, 10, -10, 1, -1};
string dp[61];
queue<int> q;

bool lessThan(string s1, string s2) {
    if (s2 == "") {
        return true;
    }

    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < 5; i++) {
        cnt1 += (s1[i] - '0');
        cnt2 += (s2[i] - '0');
    }

    if (cnt1 == cnt2) {
        return s1 < s2;
    }
    return cnt1 < cnt2;
}

int main() {
    int t;
    cin >> t;

    q.push(0);
    dp[0] = "00000";

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i = 0; i < 5; i++) {
            int next = d[i] + now;
            if (next > 0 && next <= 60) {
                string temp = dp[now];
                temp[i]++;

                if (lessThan(temp, dp[next])) {
                    dp[next] = temp;
                    q.push(next);
                }
            }
        }
    }

    while (t--) {
        int n;
        cin >> n;
        int ans[5] = {
            0,
        };
        ans[0] += n / 60;
        n %= 60;
        for (int i = 0; i < 5; i++) {
            ans[i] += (dp[n][i] - '0');
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
}