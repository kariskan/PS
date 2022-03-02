#include <iostream>
using namespace std;
string s[51];
int n, m;
int a[26];
int visit[51];
int b;
int ans;

int cal() {
    int res = 0;
    for (int i = 0; i < n; i++) {
        int len = s[i].length();
        int no = 0;
        for (int j = 4; j < len - 4; j++) {
            if (!a[s[i][j] - 'a']) {
                no = 1;
                break;
            }
        }
        if (!no) {
            res++;
        }
    }
    return res;
}

void run(int cnt, int idx) {
    if (cnt > m)return;
    if (cnt == m) {
        int res = cal();
        ans = ans < res ? res : ans;
        return;
    }
    for (int i = idx; i < 26; i++) {
        if (a[i])continue;
        a[i] = 1;
        run(cnt + 1, i + 1);
        a[i] = 0;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    a[0] = a['n' - 'a'] = a['t' - 'a'] = a['c' - 'a'] = a['i' - 'a'] = 1;
    run(5, 0);
    cout << ans;
}