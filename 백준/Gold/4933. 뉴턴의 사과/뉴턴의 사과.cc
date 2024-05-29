#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <set>
#include <cmath>
#include <string>

using namespace std;

vector<int> p;
stack<char> st;

void go(char pre) {
    if (st.empty()) {
        return;
    }
    char now = st.top();
    st.pop();
    if (now == '.') {
        return;
    }

    p[now - 'A'] = pre - 'A';
    go(now);
    go(now);
}

vector<int> makeTree() {
    p.clear();
    p.resize(26);
    string s;
    while (1) {
        cin >> s;
        if (s == "end") {
            break;
        }
        if (s == "nil") {
            st.push('.');
        } else {
            st.push(s[0]);
        }
    }
    go(-1);
    return p;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        vector<int> v1 = makeTree();
        vector<int> v2 = makeTree();

        bool flag = true;
        for (int i = 0; i < 26; i++) {
            if (v1[i] != v2[i]) {
                flag = false;
            }
        }
        if (flag) {
            cout << "true\n";
        } else {
            cout << "false\n";
        }
    }
}