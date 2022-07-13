#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
stack<char> st;

int main() {
	int n, m;
	cin >> n >> m;
	string s;
	string ans = "";
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (st.empty())st.push(s[i]);
		else {
			while (!st.empty() && m && st.top() < s[i]) {
				st.pop();
				m--;
			}
			st.push(s[i]);
		}
	}
	while (m) {
		st.pop();
		m--;
	}
	while (!st.empty()) {
		ans += st.top();
		st.pop();
	}
	reverse(ans.begin(), ans.end());
	cout << ans;
}