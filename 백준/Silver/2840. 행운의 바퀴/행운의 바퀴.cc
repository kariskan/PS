#include <iostream>
using namespace std;

int n, k, vis[26];

int main() {
    cin >> n >> k;
    string ans = "";
    for (int i = 0; i < n; i++) {
        ans += ' ';
    }
    int now = 0;
    for (int i = 0; i < k; i++) {
        int a;
        char b;
        cin >> a >> b;
        while (a--) {
            if (now == 0) {
                now = n - 1;
            } else {
                now--;
            }
        }
        if (!(ans[now] == b || ans[now] == ' ') || (ans[now] != b && vis[b - 'A'])) {
            cout << "!";
            return 0;
        }
        ans[now] = b;
        vis[b - 'A'] = 1;
    }
    for (int i = now; i < n; i++) {
        if (ans[i] == ' ') {
            cout << '?';
        } else {
            cout << ans[i];
        }
    }
    for (int i = 0; i < now; i++) {
        if (ans[i] == ' ') {
            cout << '?';
        } else {
            cout << ans[i];
        }
    }
}