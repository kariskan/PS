#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (1) {
        long long x;
        cin >> x;
        if (cin.eof()) break;
        x *= 10000000;
        vector<long long> v;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            long long a;
            cin >> a;
            v.push_back(a);
        }

        sort(v.begin(), v.end());

        long long left = 0, right = v.size() - 1, l1 = -1, l2 = -1;

        while (left < right) {
            if (v[left] + v[right] >= x) {
                if (v[left] + v[right] == x) {
                    if (abs(v[left] - v[right]) >= abs(l1 - l2)) {
                        l1 = v[left];
                        l2 = v[right];
                    }
                }
                right--;
            } else {
                left++;
            }
        }

        if (l1 != -1 && l2 != -1) {
            cout << "yes " << l1 << " " << l2 << '\n';
        } else {
            cout << "danger\n";
        }
    }
}