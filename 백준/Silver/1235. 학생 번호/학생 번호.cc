#include <iostream>
#include <set>
using namespace std;

string s[1000];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= s[0].length(); i++) {
        set<string> se;
        bool flag = true;
        for (int j = 0; j < n; j++) {
            if (se.find(s[j].substr(s[j].length() - i)) != se.end()) {
                flag = false;
                break;
            }
            se.insert(s[j].substr(s[j].length() - i));
        }
        if (flag) {
            cout << i;
            return 0;
        }
    }
}