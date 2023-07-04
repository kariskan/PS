#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, l, k;
        cin >> n >> l >> k;
        deque<int> d;
        vector<int> left, right;

        for (int i = 0; i < n; i++) {
            int c1, c2;
            cin >> c1 >> c2;

            if (c2 > 0) {
                right.push_back(l - c1 + 1);
            } else {
                left.push_back(c1 + 1);
            }
            d.push_back(c2);
        }
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());
        int li = 0, ri = 0;
        while (li < left.size() || ri < right.size()) {
            int now;
            if (li == left.size()) {
                now = d.back();
                d.pop_back();
                ri++;
            } else if (ri == right.size()) {
                now = d.front();
                d.pop_front();
                li++;
            } else {
                if (left[li] < right[ri]) {
                    li++;
                    now = d.front();
                    d.pop_front();
                } else if (left[li] == right[ri]) {
                    if (d.front() < d.back()) {
                        li++;
                        now = d.front();
                        d.pop_front();
                    } else {
                        ri++;
                        now = d.back();
                        d.pop_back();
                    }
                } else {
                    ri++;
                    now = d.back();
                    d.pop_back();
                }
            }
            k--;
            if (k == 0) {
                cout << now << '\n';
                break;
            }
        }
    }
}