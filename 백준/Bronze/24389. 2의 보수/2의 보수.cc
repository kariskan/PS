#include <algorithm>
#include <iostream>
using namespace std;

int origin[32], b[32];

int main() {
    int n;
    cin >> n;
    string s = "";
    while (n) {
        s += (n % 2 + '0');
        n /= 2;
    }
    reverse(s.begin(), s.end());
    int idx = 0;
    for (int i = 32 - (int)s.length(); i < 32; i++) {
        origin[i] = s[idx++] - '0';
        b[i] = origin[i];
    }

    for (int i = 0; i < 32; i++) {
        b[i] = 1 - b[i];
    }
    b[31]++;
    int p = 0;
    for (int i = 31; i >= 0; i--) {
        b[i] += p;
        p = 0;
        if (b[i] == 2) {
            b[i] = 0;
            p = 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < 32; i++) {
        if (origin[i] != b[i]) {
            ans++;
        }
    }

    cout << ans;
}