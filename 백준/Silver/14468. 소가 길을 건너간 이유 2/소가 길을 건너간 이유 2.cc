#include <iostream>
using namespace std;

int a[26][2];

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (a[s[i] - 'A'][0] == 0) {
            a[s[i] - 'A'][0] = i + 1;
        } else {
            a[s[i] - 'A'][1] = i + 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = i + 1; j < 26; j++) {
            if (a[i][0] < a[j][0] && a[j][0] < a[i][1] && a[i][1] < a[j][1]) {
                ans++;
            } else if (a[j][0] < a[i][0] && a[i][0] < a[j][1] &&
                       a[j][1] < a[i][1]) {
                ans++;
            }
        }
    }

    cout << ans;
}