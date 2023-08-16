#include <iostream>
using namespace std;

int main() {
    int n,m;cin>>n>>m;
    int idx = 0;
    for (int i = 0; i < n - m; i++) {
        cout << idx << ' ' << idx + 1 << '\n';
        idx++;
    }
    int k = idx++;
    while (idx < n) {
        cout << k << ' ' << idx << '\n';
        idx++;
    }
}