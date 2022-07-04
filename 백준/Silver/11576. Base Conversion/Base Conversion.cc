#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

int a, b, m;
int ar[30];

int main() {
	cin >> a >> b >> m;
	int num = 0;
	for (int i = 0; i < m; i++) {
		cin >> ar[i];
		num += pow(a, m - i - 1) * ar[i];
	}
	stack<int> st;
	int div = 0;
	while (num) {
		st.push(num % b);
		div = num = num / b;
	}
	if(div) st.push(div);
	while (!st.empty()) {
		cout << st.top() << ' ';
		st.pop();
	}
}