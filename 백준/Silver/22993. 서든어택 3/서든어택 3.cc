#include <algorithm>
#include <iostream>
using namespace std;
long long a[100000];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n);
    for (int i = 1; i < n; i++) {
        if (a[i] >= a[0]) {
            cout << "No";
            return 0;
        }
        a[0] += a[i];
    }
    cout << "Yes";
}