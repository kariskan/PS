#include <iostream>
using namespace std;

int a[3];
bool dp[51][51][51][3][3];
string s;

bool go(int aa, int bb, int cc, int pre, int ppre, string now) {
    if (aa == a[0] && bb == a[1] && cc == a[2]) {
        cout << now;
        exit(0);
    }
    if (aa > a[0] || bb > a[1] || cc > a[2]) {
        return false;
    }
    if (dp[aa][bb][cc][pre][ppre]) {
        return dp[aa][bb][cc][pre][ppre];
    }

    if (a[0] > aa) {
        go(aa + 1, bb, cc, 0, pre, now + "A");
    }
    if (a[1] > bb && pre != 1) {
        go(aa, bb + 1, cc, 1, pre, now + "B");
    }
    if (a[2] > cc && pre != 2 && ppre != 2) {
        go(aa, bb, cc + 1, 2, pre, now + "C");
    }
    return dp[aa][bb][cc][pre][ppre] = true;
}

int main() {
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        a[s[i] - 'A']++;
    }
    go(0, 0, 0, 0, 0, "");
    cout << -1;
    return 0;
}