#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(string s1, string s2) {
	if (s1.length() == s2.length())return s1 < s2;
	return s1.length() < s2.length();
}
int main() {
	int n;
	cin >> n;
	vector<string> v;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end(), compare);
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
}