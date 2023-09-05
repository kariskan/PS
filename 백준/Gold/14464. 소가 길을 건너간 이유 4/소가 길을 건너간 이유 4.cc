#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int c, n, chicken[20000];
pair<int, int> cow[20000];

struct ComparePair {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
        if (p1.second == p2.second) {
            return p1.first > p2.first; // second 값이 같을 때 first 값을 내림차순으로 정렬
        }
        return p1.second > p2.second; // second 값으로 내림차순으로 정렬
    }
};

int main() {
    cin >> c >> n;
    for (int i = 0; i < c; i++) {
        cin >> chicken[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> cow[i].first >> cow[i].second;
    }
    sort(chicken, chicken + c);
    sort(cow, cow + n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, ComparePair> pq;
    int ans = 0, idx = 0;
    for (int i = 0; i < c; i++) {
        while (idx < n && cow[idx].first <= chicken[i]) {
            pq.push(cow[idx++]);
        }
        while (!pq.empty() && pq.top().second < chicken[i]) {
            pq.pop();
        }
        if (!pq.empty()) {
            ans++;
            pq.pop();
        }
    }
    cout << ans;
}