#include <iostream>
#include <map>
using namespace std;

int n, m;
map<int, int> ma;

int main() {
    cin >> n >> m;
    ma[n] = 0;
    int idx = 1;
    int k = n;
    while (1) {
        if (ma.find((k * n) % m) != ma.end()) {
            cout << idx - ma[(k * n) % m];
            return 0;
        }
        ma[(k * n) % m] = idx;
		idx++;
		k = (k * n) % m;
    }
}