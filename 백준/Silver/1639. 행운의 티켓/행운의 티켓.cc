#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int l = 0, r = 0, ans = 0;
    for (int i = 0; i < s.length(); i++) {
        for (int j = i + 1; j < s.length(); j += 2) {
            l = 0, r = 0;
            for (int k = i; k <= (i + j) / 2; k++) {
                l += s[k] - '0';
                r += s[j - (k - i)] - '0';
            }
            if (l == r) {
                ans = max(ans, j - i + 1);
            }
        }
    }

    cout << ans;
}
