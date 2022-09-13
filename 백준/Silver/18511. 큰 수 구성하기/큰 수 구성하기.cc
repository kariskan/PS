#include <iostream>
#include <string>
using namespace std;

string n;
int k, a[3];
int ans;

void go(string s) {
	if (s.length() > n.length() || (s.length() == n.length() && s > n)) return;
	if (!s.empty()) ans = max(ans, stoi(s));

	for (int i = 0; i < k; i++) {
		s.push_back(a[i] + '0');
		go(s);
		s.pop_back();
	}
}

int main() {
	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		cin >> a[i];
	}

	go("");

	cout << ans;
}