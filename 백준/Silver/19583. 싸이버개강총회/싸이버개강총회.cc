#include <iostream>
#include <set>
using namespace std;

string s, e, q;
set<string> se, ans;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> s >> e >> q;

	while (!cin.eof()) {
		string a, b;
		cin >> a >> b;
		
		if (a <= s) {
			se.insert(b);
		}
		else if (a >= e && a <= q && se.find(b) != se.end() && ans.find(b) == ans.end()) {
			ans.insert(b);
		}
	}

	cout << ans.size();
}