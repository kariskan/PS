#include <iostream>
using namespace std;

int main() {

    while (1) {
        int n;
        cin >> n;
        if (!n) {
            break;
        }
        int maxl = 0;
        getchar();
        string s;
        getline(cin, s);
        bool flag = false;
        for (int i = 0; i < s.length(); i++) {
            if (flag && s[i] == ' ') {
                maxl = i + 1;
                break;
            }
            if (s[i] != ' ') {
                flag = true;
            }
        }
        
        if (maxl == 0) {
            maxl = (int)s.length() + 1;
        }

        for (int i = 0; i < n - 1; i++) {
            getline(cin, s);
            for (int j = maxl - 1; j < s.length(); j++) {
                if (s[j] == ' ') {
                    maxl = max(maxl, j + 1);
                    break;
                }
                if (j == s.length() - 1) {
                    maxl = max(maxl, (int)s.length() + 1);
                }
            }
        }

        cout << maxl << '\n';
    }
}