#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<long long> v;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        reverse(a.begin(), a.end());
        v.push_back(stoll(a));
    }

    sort(v.begin(), v.end());
    for (auto& i : v) {
        cout << i << '\n';
    }
}