#include <iostream>
#include <stack>
using namespace std;
long long fib[50];
int main() {
	int n;
	cin >> n;
	fib[1] = 1;
	for (int i = 2; i < 50; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	for (int i = 0; i < n; i++) {
		long long num; cin >> num;
		stack<long long> q;
		for (int i = 49; i >= 0; i--) {
			if (fib[i] <= num) {
				num -= fib[i];
				q.push(fib[i]);
			}
			if (num == 0)break;
		}
		while (!q.empty()) {
			cout << q.top() << ' ';
			q.pop();
		}
		cout << '\n';
	}
}