#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
int n, a[1000000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (v.empty() || v[v.size() - 1] < a[i]) {
            v.push_back(a[i]);
        } else {
            int l = 0, r = v.size() - 1;
            int ans = v.size() - 1;
            while (l <= r) {
                int mid = (l + r) / 2;

                if (v[mid] >= a[i]) {
                    r = mid - 1;
                    ans = min(ans, mid);
                } else {
                    l = mid + 1;
                }
            }
            v[ans] = a[i];
        }
    }

    cout << v.size();
}