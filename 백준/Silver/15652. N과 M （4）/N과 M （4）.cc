#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <set>
#include <cmath>
#include <string>
#include <sstream>
#include <map>

using namespace std;

int n, m;

void go(vector<int> seq) {
    if (seq.size() == m) {
        for (int i = 0; i < seq.size(); i++) {
            cout << seq[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (seq.empty() || seq.back() <= i) {
            seq.push_back(i);
            go(seq);
            seq.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    go({});
}