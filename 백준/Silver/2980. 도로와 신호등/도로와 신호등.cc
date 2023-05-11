#include <iostream>
using namespace std;

int t[100][3];

int main() {
    int n, l;
    cin >> n >> l;

    for (int i = 0; i < n; i++) {
        cin >> t[i][0] >> t[i][1] >> t[i][2];
    }

    int time = 0, pre = 0;
    for (int i = 0; i < n; i++) {
        time += t[i][0] - pre;
        pre = t[i][0];

        int now = time % (t[i][1] + t[i][2]);
        if (now <= t[i][1]) {
            time += t[i][1] - now;
        }
    }
    cout << time + l - pre;
}