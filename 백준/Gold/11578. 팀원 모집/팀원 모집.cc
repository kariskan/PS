#include <iostream>
#include <vector>
using namespace std;
int ans = 11, n, m;
vector<int> inp[11];

bool check(vector<int> v) {
    for (int i = 1; i <= n; i++) {
        if (!v[i]) {
            return false;
        }
    }
    return true;
}

void go(int numberOfStudent, int idx, vector<int> v) {
    if (check(v)) {
        ans = min(ans, numberOfStudent);
        return;
    }

    if (idx > m) {
        return;
    }

    go(numberOfStudent, idx + 1, v);
    for (int i = 0; i < inp[idx].size(); i++) {
        v[inp[idx][i]] = 1;
    }
    go(numberOfStudent + 1, idx + 1, v);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a;
        cin >> a;
        for (int j = 0; j < a; j++) {
            int b;
            cin >> b;
            inp[i].push_back(b);
        }
    }
    vector<int> v(11);
    go(0, 1, v);
    if (ans == 11) {
        cout << -1;
    } else {
        cout << ans;
    }
}