#include <string>
#include <vector>
#include <stack>
using namespace std;
bool check(string s) {
    stack <char> st;
    for (char c : s) {
        if (st.empty()) {
            st.push(c);
        }
        else {
            if (c == '(') {
                st.push(c);
            }
            else {
                if (st.top() != '(')return false;
                st.pop();
            }
        }
    }
    if (st.empty()) return true;
    else return false;
}

bool balanced(string s1, string s2) {
    int f1 = 0, f2 = 0;
    for (char c : s1) {
        if (c == '(')f1++;
        else f2++;
    }
    if (f1 != f2)return false;
    f1 = f2 = 0;
    for (char c : s2) {
        if (c == '(')f1++;
        else f2++;
    }
    if (f1 != f2)return false;
    return true;
}

string swap(string s) {
    s = s.substr(1, s.length() - 2);
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] == '(')s[i] = ')';
        else s[i] = '(';
    }
    return s;
}

string run(string s) {
    if (s == "") return s;
    int len = s.length();
    for (int i = 1; i <= len; i++) {
        string s1 = s.substr(0, i);
        string s2 = s.substr(i, len - i);
        if (balanced(s1, s2)) {
            if (check(s1)) {
                return s1 + run(s2);
            }
            else {
                string t = "(";
                t += run(s2) + ")";
                s1 = swap(s1);
                return t + s1;
            }
            break;
        }
    }
}
string solution(string p) {
    string answer = "";
    int len = p.length();
    if (check(p))return p;
    answer = run(p);
    return answer;
}