#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int gcd(int a, int b) {
	if (b == 0)return a;
	return gcd(b, a % b);
}

int n;
int a[100];
pair<int, int> ar[1000000];
vector<int> v;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int mcd = a[1] - a[0];
	for (int i = 2; i < n; i++) {
		mcd = gcd(mcd, a[i] - a[i - 1]);
	}
	vector<int> ans;
	for (int i = 2; i * i <= mcd; i++) {
		if (mcd % i == 0) {
			ans.push_back(i);
			if (i * i != mcd) {
				ans.push_back(mcd / i);
			}
		}
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}
	cout << mcd;
}