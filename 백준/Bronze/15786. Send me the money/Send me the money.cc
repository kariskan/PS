#include <iostream>
using namespace std;

int n, m;
string s;

int main() {
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        string t;
        cin >> t;
        int idx = 0;
        for (int j = 0; j < t.length(); j++) {
            if (t[j] == s[idx]) {
                idx++;
            }
            if (idx == s.length()) {
                break;
            }
        }
        if (idx == s.length()) {
            cout << "true\n";
        } else {
            cout << "false\n";
        }
    }
}