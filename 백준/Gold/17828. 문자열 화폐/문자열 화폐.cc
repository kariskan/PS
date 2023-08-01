#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, x;
    cin >> n >> x;
    if (n * 26 < x || n > x) {
        cout << "!";
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 26; j++) {
            if (x - j <= (n - i - 1) * 26) {
                x -= j;
                cout << (char)(j - 1 + 'A');
                break;
            }
        }
    }
}