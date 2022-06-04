#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int m1 = 1000000, m2 = -1000000;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        m1 = min(m1, a);
        m2 = max(m2, a);
    }
    cout << m1 << "\n" << m2;
}