#include <iostream>
#include <stack>
using namespace std;

string s;

bool check() {
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(s[i]);
        } else {
            if (st.top() != '(') {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

void go(int idx) {
    if (idx >= s.length()) {
        if (check()) {
            cout << s;
            exit(0);
        }
        return;
    }
    if (s[idx] != 'G') {
        go(idx + 1);
        return;
    }

    s[idx] = '(';
    go(idx + 1);
    s[idx] = ')';
    go(idx + 1);
    s[idx] = 'G';
}

int main() {
    int n;
    cin >> n;
    cin >> s;
    go(0);
}