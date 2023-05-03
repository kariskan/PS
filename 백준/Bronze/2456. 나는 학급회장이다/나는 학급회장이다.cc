#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> v(4, vector<int>(5));

bool compare(vector<int>& v1, vector<int>& v2) {
    if (v1[0] == v2[0]) {
        if (v1[3] == v2[3]) {
            if (v1[2] == v2[2]) {
                return true;
            }
            return v1[2] > v2[2];
        }
        return v1[3] > v2[3];
    }
    return v1[0] > v2[0];
}

int main() {
    cin >> n;
    v[1][4] = 1;
    v[2][4] = 2;
    v[3][4] = 3;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        v[1][0] += a;
        v[1][a]++;

        v[2][0] += b;
        v[2][b]++;

        v[3][0] += c;
        v[3][c]++;
    }

    sort(v.begin() + 1, v.end(), compare);

    if (v[1][1] == v[2][1] && v[1][2] == v[2][2] && v[1][0] == v[2][0]) {
        cout << 0 << ' ' << v[1][0];
    } else {
        cout << v[1][4] << ' ' << v[1][0];
    }
}