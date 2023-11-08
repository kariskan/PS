#include <iostream>
#include <set>
#include <sstream>
#include <vector>
using namespace std;

char toAnotherCase(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 'a';
    }
    return c - 'a' + 'A';
}

int main() {
    int n;
    cin >> n;

    set<char> se;

    getchar();
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);

        vector<string> split;

        stringstream ss(s);
        string temp;
        while (getline(ss, temp, ' ')) {
            split.push_back(temp);
        }

        int idx = -1, len = 0;
        for (auto &i : split) {
            if (se.find(i[0]) == se.end() &&
                se.find(toAnotherCase(i[0])) == se.end()) {
                se.insert(i[0]);
                idx = len;
                break;
            }
            len += i.length() + 1;
        }

        if (idx == -1) {
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == ' ') {
                    continue;
                }
                if (se.find(s[i]) == se.end() &&
                    se.find(toAnotherCase(s[i])) == se.end()) {
                    se.insert(s[i]);
                    idx = i;
                    break;
                }
            }
        }

        for (int i = 0; i < s.length(); i++) {
            if (idx == i) {
                cout << "[" << s[i] << "]";
            }
            else {
                cout << s[i];
            }
        }

        cout << '\n';
    }
}