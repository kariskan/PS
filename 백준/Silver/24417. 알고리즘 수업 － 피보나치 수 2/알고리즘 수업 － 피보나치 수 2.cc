#include <iostream>
using namespace std;

int n;

int main() {
    cin >> n;
    int a = 1, b = 1, c = 2;

    for (int i = 3; i <= n; i++) {
        c = (a + b) % 1000000007;
        a = b;
        b = c;
    }
    
    cout << c << ' '<< n - 2;
}