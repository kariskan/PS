#include <iostream>
#include <stack>
using namespace std;

stack<int> st;
int n;

int main() {
	cin >> n;
	int last = 0;

	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		st.push(num);

		while (!st.empty() && st.top() == last + 1) {
			last++;
			st.pop();
		}
	}

	if (st.empty()) cout << "Nice";
	else cout << "Sad";
}