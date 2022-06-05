#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;
int ar[1000000];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		ar[i] = c;
		v.push_back(c);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < n; i++) {
		int left = 0;
		int right = v.size() - 1;
		int mid = (left + right) / 2;
		while (left <= right) {
			mid = (left + right) / 2;
			if (v[mid] == ar[i]) {
				cout << mid << " ";
				break;
			}
			else if (v[mid] < ar[i]) {
				left = mid + 1;
			}
			else right = mid - 1;
		}
	}
}