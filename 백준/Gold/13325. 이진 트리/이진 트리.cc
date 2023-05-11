#include <iostream>
#include <vector>
using namespace std;

int n, ans, maxWeight;
vector<vector<pair<int, int>>> v;
pair<int, int> child[5000000];

int go(int node, int pre, int sum) {  // 자식 가중의 합 최대를 리턴

    int res = 0;
    for (auto& i : v[node]) {
        if (i.first != pre) {
            res = i.second + go(i.first, pre, sum + i.second);
            if (child[node].first == 0) {
                child[node].first = res;
            } else {
                child[node].second = res;
            }
        }
    }

    return max(child[node].first, child[node].second);
}

void go2(int node, int pre, int sum) {
    int idx = 0;
    for (auto& i : v[node]) {
        if (i.first != pre) {
            int p;
            if (idx == 0) {  // leftNode
                p = maxWeight - child[node].first - sum;
            } else {
                p = maxWeight - child[node].second - sum;
            }
            ans += p;
            sum += p;
            go2(i.first, node, sum + i.second);
            sum -= p;
            idx++;
        }
    }
}

int main() {
    cin >> n;
    v.resize(1 << (n + 1));
    int p = 1;
    int nodeCount = 0;
    for (int i = 0; i < n; i++) {
        nodeCount += p * 2;
        p *= 2;
    }

    for (int i = 2; i <= nodeCount + 1; i++) {
        int a;
        cin >> a;
        ans += a;
        v[i / 2].push_back({i, a});
    }
    go(1, 0, 0);
    maxWeight = max(child[1].first, child[1].second);
    go2(1, 0, 0);

    cout << ans;
}