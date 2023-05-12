#include <iostream>
using namespace std;

int ans;

int main() {
    string s;
    cin >> s;
    int l = 0, r = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            l++;
        } else {
            r++;
        }
        if (l < r) {
            ans++;
            r--;
        }
    }
    cout << ans + l - r;
}