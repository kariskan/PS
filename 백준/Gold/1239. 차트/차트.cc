#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v, order;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
        order.push_back(i);
    }
    int ans = 0;
    do {
        vector<int> now;
        for (int i = 0; i < n; i++) {
            now.push_back(v[order[i]]);
        }
        int sum = 0, res = 0;
        for (int i = 0; i < n; i++) {
            sum += now[i];
            if (sum == 50) {
                int t = 0, idx = i + 1;
                for (int j = 0; j <= i; j++) {
                    t += now[j];
                    int s = 0;
                    for (int k = idx; k < n; k++) {
                        s += now[k];
                        if (s > t) {
                            break;
                        } else if (s == t) {
                            res++;
                            t = 0, idx = k + 1;
                            break;
                        }
                    }
                }
                ans = max(ans, res);
            } else if (sum > 50) {
                break;
            }
        }
    } while (next_permutation(order.begin(), order.end()));
    cout << ans;
}