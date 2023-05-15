#include <iostream>
using namespace std;

int a[6], b[6];

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    for (int i = 0; i < 6; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 6; i++) {
        cin >> b[i];
    }
    int cnt = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (a[i] > b[j]) {
                cnt++;
            }
        }
    }
    
    int g = gcd(36, cnt);
    
    cout << cnt / g << "/" << 36 / g;
}