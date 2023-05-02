#include <iostream>
#include <string>
using namespace std;
int k[4];
int a, c, g, t;
bool check() { return k[0] >= a && k[1] >= c && k[2] >= g && k[3] >= t; }
int main() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    cin >> a >> c >> g >> t;

    for (int i = 0; i < m; i++) {
        if (s[i] == 'A') {
            k[0]++;
        } else if (s[i] == 'C') {
            k[1]++;
        } else if (s[i] == 'G') {
            k[2]++;
        } else {
            k[3]++;
        }
    }
    int ans = check() ? 1 : 0;

    for (int i = 1; i <= n - m; i++) {
        if (s[i - 1] == 'A') {
            k[0]--;
        } else if (s[i - 1] == 'C') {
            k[1]--;
        } else if (s[i - 1] == 'G') {
            k[2]--;
        } else {
            k[3]--;
        }

        if (s[i + m - 1] == 'A') {
            k[0]++;
        } else if (s[i + m - 1] == 'C') {
            k[1]++;
        } else if (s[i + m - 1] == 'G') {
            k[2]++;
        } else {
            k[3]++;
        }
        if (check()) {
            ans++;
        }
    }

    cout << ans;
}