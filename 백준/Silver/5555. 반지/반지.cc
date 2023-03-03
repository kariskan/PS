#include <iostream>
using namespace std;

string s;
int n;

int main() {
	cin >> s >> n;
	
	int ans = 0;
	
	for (int i = 0; i < n; i++) {
		string t;
		cin >> t;
		for (int j = 0; j < t.length(); j++) {
			string temp = "";
			for (int k = 0; k < s.length(); k++) {
				temp += t[(j + k) % t.length()];
			}
			if (s == temp) {
				ans++;
				break;
			}
		}
	}

	cout << ans;
}