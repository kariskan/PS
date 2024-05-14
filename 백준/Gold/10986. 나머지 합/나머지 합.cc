#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <map>
using namespace std;

long long arr[1000001], mod[1001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;

	long long answer = 0;

	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		arr[i] = arr[i - 1] + a;
		if (arr[i] % m == 0) {
			answer++;
		}
		answer += mod[arr[i] % m];
		mod[arr[i] % m]++;
	}
	cout << answer << ' ';
}