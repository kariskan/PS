#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, l;
	cin >> n >> l;
	int a[1000];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		if (l >= a[i])l++;
	}
	cout << l;
}