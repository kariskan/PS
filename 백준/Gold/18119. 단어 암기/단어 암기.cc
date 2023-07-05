#include <iostream>
using namespace std;

int bits[10000], n, m, know;
string s[10000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < s[i].length(); j++) {
            know |= (1 << (s[i][j] - 'a'));
            bits[i] |= (1 << (s[i][j] - 'a'));
        }
    }
    for (int i = 0; i < m; i++) {
        int a;
        char b;
        cin >> a >> b;
        if (a == 1) {
            know &= ~(1 << (b - 'a'));
        } else {
            know |= (1 << (b - 'a'));
        }
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if ((bits[j] & know) == bits[j]) {
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
}