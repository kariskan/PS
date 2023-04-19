#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    
    string ans = "";
    
    for (int i = 0; i < s.length(); i += 3) {
        int n = 0, m = 1;
        for (int j = i; j < i + 3; j++) {
            if (s[j] == '1') {
                n += m;
            }
            m *= 2;
        }
        ans += to_string(n);
    }
    
    reverse(ans.begin(), ans.end());
    
    cout << ans;
}