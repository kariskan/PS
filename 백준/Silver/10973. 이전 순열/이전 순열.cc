#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	if (prev_permutation(v.begin(), v.end())) {
		int vSize = v.size();
		for (int i = 0; i < n; i++) {
			cout << v[i] << " ";
		}
	}
	else cout << -1;
}