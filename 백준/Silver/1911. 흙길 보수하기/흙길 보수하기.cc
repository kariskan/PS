#include <algorithm>
#include <iostream>
using namespace std;

pair<int, int> a[10000];

int main() {
    int n, l;
    cin >> n >> l;

    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a, a + n);

    int now = a[0].first;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (now < a[i].first) {
            now = a[i].first;
        }
        int req = (a[i].second - now + l - 1) / l;
        ans += req;
        now += req * l;
    }
    
    cout << ans;
}