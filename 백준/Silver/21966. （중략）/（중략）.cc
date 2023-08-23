#include <iostream>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    if (s.length() <= 25) {
        cout << s;
    } else {
        string t = s.substr(11, s.length() - 22);
        bool flag = true;
        for (int i = 0; i < t.length() - 1; i++) {
            if (t[i] == '.') {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << s.substr(0, 11) << "..." << s.substr(s.length() - 11);
        } else {
            cout << s.substr(0, 9) << "......" << s.substr(s.length() - 10);
        }
    }
}