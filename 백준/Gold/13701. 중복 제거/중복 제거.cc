#include <iostream>

using namespace std;

int check[(1 << 25) / 32];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    while (cin >> n) {
        if (!(check[n / 32] & (1 << (n % 32)))) {
            check[n / 32] += (1 << (n % 32));
            cout << n << " ";
        }
    }
    return 0;
}