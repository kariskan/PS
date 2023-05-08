#include <iostream>
using namespace std;

int n, m;

int main() {
    cin >> n;
    while (n--) {
        cin >> m;
        int sum = 0, ma = 0, cnt = 0, idx;
        for (int i = 1; i <= m; i++) {
            int a;
            cin >> a;
            sum += a;
            if (ma < a) {
                cnt = 1;
                ma = a;
                idx = i;
            } else if (ma == a) {
                cnt++;
            }
        }
        if (cnt == 1) {
            if (ma > sum / 2) {
                cout << "majority winner " << idx << '\n';
            } else {
                cout << "minority winner " << idx << '\n';
            }
        } else {
            cout << "no winner\n";
        }
    }
}