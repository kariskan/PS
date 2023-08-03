#include <iostream>
#include <map>
using namespace std;

int inp[51];

int main() {
    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        inp[a]++;
    }
    for (int i = 50; i >= 0; i--) {
        if (inp[i] == i) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
}