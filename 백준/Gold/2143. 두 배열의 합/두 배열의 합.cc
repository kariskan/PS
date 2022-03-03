#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long a[1000], b[1000];
int main() {
    int t, n, m;
    cin >> t >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    vector<long long> v1, v2;
    for (int i = 0; i < n; i++) {
        long long sum = 0;
        for (int j = i; j < n; j++) {
            sum += a[j];
            v1.push_back(sum);
        }
    }
    for (int i = 0; i < m; i++) {
        long long sum = 0;
        for (int j = i; j < m; j++) {
            sum += b[j];
            v2.push_back(sum);
        }
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int p1 = 0, p2 = v2.size() - 1;
    long long ans = 0;
    while (p1 < v1.size() && p2 < v2.size()) {
        if (v1[p1] + v2[p2] == t) {
            p1++;
            p2--;
            long long lC = 1, rC = 1;
            while (p1 < v1.size() && v1[p1] == v1[p1 - 1]) {
                p1++;
                lC++;
            }
            while (p2 >= 0 && v2[p2] == v2[p2 + 1]) {
                p2--;
                rC++;
            }
            ans += lC * rC;
        }
        else if (v1[p1] + v2[p2] < t) {
            p1++;
        }
        else {
            p2--;
        }
    }
    cout << ans;
}