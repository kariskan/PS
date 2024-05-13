#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <map>
using namespace std;

int n;
pair<int, int> child[200001];

void traversal(int node, long long k) {
	if (child[node].first == -1 && child[node].second == -1) {
		cout << node;
		exit(0);
	}
	if (child[node].first == -1) {
		traversal(child[node].second, k);
	}
	else if (child[node].second == -1) {
		traversal(child[node].first, k);
	}
	else {
		if (k % 2 == 1) {
			traversal(child[node].first, k - k / 2);
		}
		else {
			traversal(child[node].second, k - k / 2);
		}
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		child[i + 1] = { u,v };
	}

	long long k;
	cin >> k;
	traversal(1, k);
}