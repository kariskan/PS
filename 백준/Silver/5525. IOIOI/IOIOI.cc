#include <iostream>
#include <vector>
using namespace std;
int a[1000000];
vector<int> v;
int main() {
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	int len = s.length();
	int vi = 0;
	for (int i = 0; i < len; i++) {
		if (i < len - 2 && s[i] == 'I' && s[i + 1] == 'O' && s[i + 2] == 'I') {
			if (v.empty())v.push_back(1);
			else v.push_back(v[vi - 1] + 1);
			vi++;
			i++;
		}
		else {
			v.push_back(0);
			vi++;
		}
	}
	int ans = 0;
	for (int i = 0; i < vi; i++) {
		if (v[i] >= n)ans++;
	}
	cout << ans;
}