#include <iostream>
#include <algorithm>

using namespace std;

int n, m, idx = -1;
string s;

int main() {
    char map[1000][27];
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    cin >> s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
            cin >> map[i][j];
        }
        if (map[i][0] == '?') {
            idx = i;
        }
    }

    string fs = "";
    for (int i = 0; i < m; i++) {
        fs += 'A' + i;
    }
    for (int i = 0; i < idx; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (map[i][j] == '-') {
                swap(fs[j], fs[j + 1]);
            }
        }
    }
    for (int i = n - 1; i > idx; i--) {
        for (int j = 0; j < m - 1; j++) {
            if (map[i][j] == '-') {
                swap(s[j], s[j + 1]);
            }
        }
    }

    string ans = "";
    for (int i = 0; i < m - 1; i++) {
        if (fs[i] == s[i]) {
            ans += '*';
        } else if (fs[i] == s[i + 1] && fs[i + 1] == s[i]) {
            ans += '-';
            swap(fs[i], fs[i + 1]);
        } else {
            for (int j = 0; j < m - 1; j++) {
                cout << "x";
            }
            return 0;
        }
    }
    cout << ans;
}
