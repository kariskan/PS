#include <algorithm>
#include <iostream>
using namespace std;

int n;
pair<int, int> a[50];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    stable_sort(a, a + n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[j].second == i) {
                cout << j << ' ';
            }
        }
    }
}