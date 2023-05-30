#include <algorithm>
#include <iostream>
using namespace std;

int n, a[20001];

int main() {
    cin >> n;
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    if (n % 2 == 0) {
        cout << a[n / 2 - 1];
    } else {
        cout << a[n / 2];
    }
}