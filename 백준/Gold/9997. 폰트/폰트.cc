#include <iostream>
using namespace std;

long long n, ans, a[25];
string s[25];

void go(int idx, long long k) {
    if (idx >= n) {
        if (k == (1 << 26) - 1) {
            ans++;
        }
        return;
    }

    go(idx + 1, k);
    go(idx + 1, k | a[idx]);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < s[i].length(); j++) {
            a[i] |= (1 << (s[i][j] - 'a'));
        }
    }

    go(0, 0);

    cout << ans;
}