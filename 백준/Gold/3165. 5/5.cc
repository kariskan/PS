#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

string n, s;
int k;

int getNumberOfFive(string s) {
    int res = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '5') {
            res++;
        }
    }
    return res;
}

void go(int idx, bool flag) {
    if (idx >= s.length() || getNumberOfFive(s) >= k) {
        return;
    }

    if (flag) {
        s[idx - 1] = '5';
    }

    if (getNumberOfFive(s) >= k) {
        return;
    }

    if (s[idx] < '5') {
        s[idx] = '5';
        go(idx + 1, false);
    } else if (s[idx] == '5') {
        go(idx + 1, false);
    } else {
        int add = 1;
        s[idx] = '0';
        for (int i = idx + 1; i < s.length(); i++) {
            if (s[i] == '9') {
                add = 1;
                s[i] = '0';
            } else {
                s[i] += add;
                add = 0;
                break;
            }
        }
        if (add == 1) {
            s += "1";
        }
        go(idx + 1, true);
    }
}

int main() {
    cin >> n >> k;
    s = to_string(stoll(n) + 1);
    reverse(s.begin(), s.end());
    go(0, false);

    int c = getNumberOfFive(s);

    for (int i = 0; i < k - c; i++) {
        s += "5";
    }

    reverse(s.begin(), s.end());
    cout << s;
}