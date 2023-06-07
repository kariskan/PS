#include <climits>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

long long n, ans = INT_MIN;
string inp;

long long calc(long long a, long long b, char op) {
    if (op == '+') {
        return a + b;
    }
    if (op == '-') {
        return a - b;
    }
    return a * b;
}

long long res(string s) {
    vector<long long> st;
    vector<char> op;

    // 괄호 제거
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            long long a = calc(s[i + 1] - '0', s[i + 3] - '0', s[i + 2]);
            st.push_back(a);
            i += 4;
        } else if (s[i] >= '0' && s[i] <= '9') {
            st.push_back(s[i] - '0');
        } else {
            op.push_back(s[i]);
        }
    }
    vector<long long> st2;
    vector<char> op2;
    st2.push_back(st[0]);

    // 곱하기 제거
    for (int i = 0; i < op.size(); i++) {
        if (op[i] == '*') {
            int idx = i + 1;
            long long r = st2.back() * st[i + 1];
            st2.pop_back();
            while (idx < op.size() && op[idx] == '*') {
                r *= st[idx + 1];
                idx++;
            }
            i = idx - 1;
            st2.push_back(r);
        } else {
            op2.push_back(op[i]);
            st2.push_back(st[i + 1]);
        }
    }

    long long result = st2[0];
    for (int i = 0; i < op2.size(); i++) {
        result = calc(result, st2[i + 1], op2[i]);
    }

    return result;
}

void go(int idx, string s) {
    if (idx > inp.length()) {
        ans = max(ans, res(s));
        return;
    }

    if (idx <= (int)inp.length() - 3) {
        if (idx == (int)inp.length() - 3) {
            go(idx + 4, s + '(' + inp[idx] + inp[idx + 1] + inp[idx + 2] + ')');
        } else {
            go(idx + 4, s + '(' + inp[idx] + inp[idx + 1] + inp[idx + 2] + ')' +
                            inp[idx + 3]);
        }
        go(idx + 2, s + inp[idx] + inp[idx + 1]);
    } else {
        go(idx + 2, s + inp[idx]);
    }
}

int main() {
    cin >> n >> inp;
    go(0, "");
    cout << ans;
}