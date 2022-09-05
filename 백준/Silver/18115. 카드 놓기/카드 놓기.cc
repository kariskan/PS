#include <iostream>
#include <deque>
using namespace std;

deque<int> d;
int inp[1000001];

int main() {
	int n; cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> inp[i];
	}

	for (int i = n; i >= 1; i--) {
		int a = inp[i];

		if (a == 1) {
			d.push_front(n - i + 1);
		}
		else if (a == 2) {
			int t = d.front();
			d.pop_front();
			d.push_front(n - i + 1);
			d.push_front(t);
		}
		else {
			d.push_back(n - i + 1);
		}
	}

	for (int i = 0; i < n; i++) {
		cout << d.front() << ' ';
		d.pop_front();
	}
}