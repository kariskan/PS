#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <map>
#include <cmath>
#include <sstream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    // 5 4 3 2 1 9
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        if (!st.empty()) {
            while (!st.empty() && m && st.top() < s[i]) {
                st.pop();
                m--;
            }
        }
        st.push(s[i]);
    }

    while (m--) {
        st.pop();
    }
    string ans = "";
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());

    cout << ans;
}
