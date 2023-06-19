#include <iostream>
using namespace std;

int n, m, w;

int main() {
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    int len = s.length();
    for (int i = 0; i < len; i++) {
        int tm = m, tw = w;
        if (s[0] == 'W') {
            tw++;
        } else {
            tm++;
        }
        if (abs(tw - tm) <= n) {
            s.erase(s.begin());
            m = tm;
            w = tw;
            ans++;
            continue;
        }
        tm = m, tw = w;
        if (s.length() > 1 && s[0] != s[1]) {
            if (s[1] == 'W') {
                tw++;
            } else {
                tm++;
            }
            if (abs(tw - tm) <= n) {
                s.erase(s.begin() + 1);
                m = tm;
                w = tw;
                ans++;
                continue;
            }
        }
    }
    
    cout << ans;
}