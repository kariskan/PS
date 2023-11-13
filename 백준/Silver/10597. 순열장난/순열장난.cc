#include <iostream>
#include <string>

using namespace std;

int check[100], maxNum;
string s;

bool ok() {
    for (int i = 1; i <= maxNum; i++) {
        if (!check[i]) {
            return false;
        }
    }
    return true;
}

void go(string seq, int idx) {
    if (s[idx] == '0') {
        return;
    }
    if (idx >= s.length()) {
        if (ok()) {
            cout << seq;
            exit(0);
        }
    }

    string now = "";
    for (int i = idx; i < s.length(); i++) {
        now += s[i];
        int n = stoi(now);
        if (n > maxNum) {
            break;
        }
        if (n <= maxNum && n > 0 && !check[n]) {
            check[n] = 1;
            go(seq + now + " ", i + 1);
            check[n] = 0;
        }
    }
}

int main() {
    cin >> s;
    string t = "";
    for (int i = 1;; i++) {
        t += to_string(i);
        if (t.length() == s.length()) {
            maxNum = i;
            break;
        }
    }
    go("", 0);
}
