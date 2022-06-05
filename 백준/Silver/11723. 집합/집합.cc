#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int n;
		if (s == "add") {
			cin >> n;
			sum = sum | (1 << n);
		}
		else if (s == "check") {
			cin >> n;
			if (sum & (1 << n))cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (s == "toggle") {
			cin >> n;
			sum = sum ^ (1 << n);
		}
		else if (s == "remove") {
			cin >> n;
			sum = sum & ~(1 << n);
		}
		else if (s == "all") {
			sum = (1 << 21) - 1;
		}
		else {
			sum = 0;
		}
	}
}