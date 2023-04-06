#include <iostream>
using namespace std;

struct ob {
    int start;
    int end;
    int interval;
};

ob arr[1000000];

int main() {
    int n, k, d;
    cin >> n >> k >> d;

    int l = 1, r = n;

    for (int i = 0; i < k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        arr[i] = {a, b, c};
    }

    int ans = 0;

    while (l <= r) {
        int m = (l + r) / 2;

        long long cnt = 0;

        for (int i = 0; i < k; i++) {
            if (m < arr[i].start) {
                continue;
            }

            cnt += (min(m, arr[i].end) - arr[i].start) / arr[i].interval + 1;
        }

        if (cnt >= d) {
            r = m - 1;
            ans = m;
        } else {
            l = m + 1;
        }
    }

    cout << ans;
}