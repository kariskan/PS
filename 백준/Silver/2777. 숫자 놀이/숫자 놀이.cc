#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
bool flag;
vector<int> factorization(int n) {
    vector<int> res;
    while (n > 1) {
        for (int i = 2; i <= n; i++) {
            if (i >= 10) {
                flag = false;
                return res;
            }
            if (n % i == 0) {
                res.push_back(i);
                n /= i;
                break;
            }
        }
    }

    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans = 1;
        flag = true;

        v = factorization(n);
        if (!flag) {
            cout << "-1\n";
            continue;
        }
        sort(v.begin(), v.end());

        int pre = 1;
        for (int i = 0; i < v.size(); i++) {
            if (pre * v[i] >= 10) {
                ans++;
                pre = v[i];
            } else {
                pre *= v[i];
            }
        }

        cout << ans << '\n';
    }
}