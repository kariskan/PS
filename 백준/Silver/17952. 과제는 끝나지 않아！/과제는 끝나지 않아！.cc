#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<pair<int, int>> st;
    int n, ans = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            int b, c;
            cin >> b >> c;
            st.push({b, c});
        }
        if (!st.empty()) {
            int score = st.top().first;
            int second = st.top().second;
            st.pop();
            second--;
            if (second == 0) {
                ans += score;
            } else {
                st.push({score, second});
            }
        }
    }
    
    cout << ans;
}