#include <iostream>
#include <stack>
using namespace std;

int main() {
	int cnt = 1;
	while (1) {
		string s;
		cin >> s;
		if (s[0] == '-')break;
		int ans = 0;
		stack<char> st;
		for (int i = 0; i < s.length(); i++) {
			st.push(s[i]);
			if (s[i] == '{') {
				continue;
			}
			else {
				st.pop();
				if (st.empty()) {
					st.push('{');
					ans++;
				}
				else {
					if (st.top() != '{') {
						ans++;
					}
					st.pop();
				}
			}
		}
		while (!st.empty()) {
			if (st.top() == '{') {
				st.pop(); ans++; st.push('}');
			}
			else {
				st.pop();
				if (st.top() != '{') {
					ans++;
				}
				st.pop();
			}
		}
		cout << cnt++ << ". " << ans << '\n';
	}
}