#include <iostream>
#include <stack>
using namespace std;

stack<int> st;
string s;

int main() {
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            st.push(s[i] - '0');
        } else {
            int second = st.top();
            st.pop();
            int first = st.top();
            st.pop();
            if (s[i] == '+') {
                st.push(first + second);
            } else if (s[i] == '-') {
                st.push(first - second);
            } else if (s[i] == '*') {
                st.push(first * second);
            } else {
                st.push(first / second);
            }
        }
    }
    cout << st.top();
}