#include <iostream>
using namespace std;

int n, a[250001];

int main() {
    cin >> n;
    int erased = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i - erased == a[i]) {
            continue;
        } else {
            erased++;
        }
    }
    cout << erased;
}