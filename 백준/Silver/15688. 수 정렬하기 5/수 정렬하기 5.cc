#include <algorithm>
#include <iostream>
using namespace std;

int a[1000000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        a[i] = k;
    }

    sort(a, a + n);

    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
}