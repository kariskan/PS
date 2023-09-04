#include <iostream>
#include <vector>
using namespace std;

int a[100000], b[100000];

int main() {
    int x, y, n;
    cin >> x >> y >> n;
    int A = 0, B = 0;
    int alast = -300, blast = -300;
    for (int i = 0; i < n; i++) {
        int t1, t2;
        char c;
        cin >> t1 >> c >> t2;
        for (int j = 0; j < t2; j++) {
            if (c == 'B') {
                int m = max(alast + x, t1 + j * x);
                a[m]++;
                alast = m;
            } else {
                int m = max(blast + y, t1 + j * y);
                b[m]++;
                blast = m;
            }
        }
    }
    vector<int> an, bn;
    int cnt = 1;
    for (int i = 0; i < 100000; i++) {
        while (a[i]--) {
            an.push_back(cnt++);
        }
        while (b[i]--) {
            bn.push_back(cnt++);
        }
    }
    cout << an.size() << '\n';
    for (int i = 0; i < an.size(); i++) {
        cout << an[i] << ' ';
    }
    cout << '\n';
    cout << bn.size() << '\n';
    for (int i = 0; i < bn.size(); i++) {
        cout << bn[i] << ' ';
    }
}