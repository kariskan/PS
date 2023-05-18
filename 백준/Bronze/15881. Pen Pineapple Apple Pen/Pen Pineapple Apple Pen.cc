#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'p') {
            if (s.substr(i, 4) == "pPAp") {
                ans++;
                i += 3;
            }
        }
    }

    cout << ans;
}