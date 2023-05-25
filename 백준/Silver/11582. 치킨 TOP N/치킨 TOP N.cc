#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int a[1 << 20], n, k;

void merge(vector<vector<int>> v) {
    vector<int> sorted;
    for (int i = 0; i < v.size(); i += 2) {
        vector<int> left = v[i];
        vector<int> right = v[i + 1];

        int l = 0, r = 0;

        while (l < v[i].size() && r < v[i + 1].size()) {
            if (v[i][l] < v[i + 1][r]) {
                sorted.push_back(v[i][l++]);
            } else {
                sorted.push_back(v[i + 1][r++]);
            }
        }

        if (l >= v[i].size()) {
            while (r < v[i + 1].size()) {
                sorted.push_back(v[i + 1][r++]);
            }
        } else {
            while (l < v[i].size()) {
                sorted.push_back(v[i][l++]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        a[i] = sorted[i];
    }
}

void mergeSort(int cnt) {
    if (n / (int)pow(2, cnt) == k) {
        for (int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }
        exit(0);
    }

    vector<vector<int>> v;
    vector<int> temp;
    int c = 0;
    for (int i = 0; i < n; i++) {
        temp.push_back(a[i]);
        if (temp.size() == (int)pow(2, cnt)) {
            v.push_back(temp);
            temp.clear();
        }
    }

    merge(v);
    mergeSort(cnt + 1);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> k;
    mergeSort(0);
}