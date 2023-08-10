#include <vector>
#include <iostream>
using namespace std;

int a[300000];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int p = n, cnt = 0;
    
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == p) {
            cnt++;
            p--;
        }
    }
    
    cout << n - cnt;
}