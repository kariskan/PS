#include <iostream>
using namespace std;
int a[100000];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int p1 = 0, p2 = 0;
    int sum = a[p1];
    int minLen = 1000000;
    while (p1 <= p2 && p2 < n) {
        if (sum >= m) {
            minLen = min(minLen, p2 - p1 + 1);
            sum -= a[p1++];
            if (p1 > p2) {
                p2 = p1;
                sum = a[p1];
            }
        }
        else {
            sum += a[++p2];
        }
    }
    if (minLen == 1000000)minLen = 0;
    cout << minLen;
}