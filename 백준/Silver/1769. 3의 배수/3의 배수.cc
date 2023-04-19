#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int a = 0, ans = s.length() > 1 ? 1 : 0;
    for (int i = 0; i < s.length(); i++) {
        a += s[i] - '0';
    }

    while (a >= 10) {
        int t = 0;
        while (a) {
            t += a % 10;
            a /= 10;
        }
        a = t;
        ans++;
    }

    cout << ans << " " << (a % 3 == 0 ? "YES" : "NO");
}