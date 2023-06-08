#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
set<string> se;
int main() {
    int n;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (se.empty()) {
            se.insert(s);
            continue;
        }
        bool flag = false;
        for (auto &j : se) {
            if (j.length() != s.length()) {
                continue;
            }
            for (int k = 0; k < s.length(); k++) {
                if (j == s.substr(k) + (k == 0 ? "" : s.substr(0, k))) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                break;
            }
        }
        if (!flag) {
            se.insert(s);
        }
    }

    cout << se.size();
}