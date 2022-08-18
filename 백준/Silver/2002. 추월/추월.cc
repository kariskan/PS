#include <iostream>
#include <map>
#include <vector>
using namespace std;

int n;
map<string, int> m;
vector<string> v;

int main() {

	cin >> n;

	int ans = 0;

	for (int i = 0; i < n * 2; i++) {
		string s; cin >> s;

		if (i < n) {
			m[s] = i + 1;
		}
		else {
			v.push_back(s);
		}
	}

	for (int i = 0; i < v.size(); i++) {
		string s = v[i];

		for (int j = i + 1; j < v.size(); j++) {
			if (m[s] > m[v[j]]) {
				ans++;
				break;
			}
		}
	}

	cout << ans;
}