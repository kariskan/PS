#include <iostream>
using namespace std;

string a, b;
int ans = 51;

int main() {
	cin >> a >> b;
	for (int i = 0; i <= b.length() - a.length(); i++) {
		string t = b.substr(i, a.length());
		int cnt = 0;
		for (int j = 0; j < t.length(); j++) {
			if (a[j] != t[j])cnt++;
		}
		ans = min(ans, cnt);
	}
	cout << ans;
}