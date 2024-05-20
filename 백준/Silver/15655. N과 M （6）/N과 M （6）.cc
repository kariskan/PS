#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <climits>
#include <cmath>
#include <deque>
#include <stack>
#include <queue>

using namespace std;

int n, m;
vector<int> num;
vector<vector<int>> answer;

void go(int idx, vector<int> seq) {
    if (seq.size() == m) {
        answer.push_back(seq);
        return;
    }
    if (idx >= num.size()) {
        return;
    }
    go(idx + 1, seq);
    seq.push_back(num[idx]);
    go(idx + 1, seq);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        num.push_back(a);
    }
    sort(num.begin(), num.end());
    go(0, {});
    sort(answer.begin(), answer.end());
    for (auto &i: answer) {
        for (auto &j: i) {
            cout << j << ' ';
        }
        cout << '\n';
    }
}