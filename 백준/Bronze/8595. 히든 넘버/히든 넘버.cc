#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    long long ans = 0;

    for (int i = 0; i < n; i++) {
        if (!(s[i] >= '0' && s[i] <= '9')) {
            continue;
        }
        int idx = i;
        while (idx < n && s[idx] >= '0' && s[idx] <= '9') {
            idx++;
        }
        if (idx - i - 1 > 6) {
            i = idx - 1;
            continue;
        }
        ans += stoll(s.substr(i, idx - i));
        i = idx - 1;
    }
    
    cout << ans;
}