#include <iostream>
#include <stack>
using namespace std;
double arr[26] = { 0, };
int main() {
	int n;
	cin >> n;
	string a;
	cin >> a;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	stack <double> s;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] >= 'A' && a[i] <= 'Z') {
			s.push(arr[a[i]-'A']);
		}
		else {
			double a2 = s.top(); s.pop();
			double a1 = s.top(); s.pop();
			if (a[i] == '+') {
				s.push(a1 + a2);
			}
			else if (a[i] == '-') {
				s.push(a1 - a2);
			}
			else if (a[i] == '*') {
				s.push(a1 * a2);
			}
			else s.push(a1 / a2);
		}
	}
	double ans = s.top();
	cout << fixed;
	cout.precision(2);
	cout << ans;
}