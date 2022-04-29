#include <string>
#include <vector>
#include <stack>
using namespace std;
int tree[200001];
int segtree[800004];
int init(int start, int end, int num) {
    if (start == end) return segtree[num] = tree[start];

    int mid = (start + end) / 2;
    return segtree[num] = max(init(start, mid, num * 2), init(mid + 1, end, num * 2 + 1));
}
int query(int start, int end, int left, int right, int num) {
    if (end < left || start > right)return -1;
    if (left <= start && right >= end) return segtree[num];
    int mid = (start + end) / 2;
    int m1 = query(start, mid, left, right, num * 2);
    int m2 = query(mid + 1, end, left, right, num * 2 + 1);
    if (m1 == -1) return m2;
    if (m2 == -1)return m1;
    return max(m1, m2);
}
int solution(vector<int> stones, int k) {
    int answer = 200000001;
    int n = stones.size();
    for (int i = 0; i < n; i++) {
        tree[i + 1] = stones[i];
    }
    init(1, n, 1);
    int start = 0, end = k - 1;
    while (start < n - k + 1) {
        answer = min(answer, query(1, n, start + 1, end + 1, 1));
        start++; end++;
    }
    return answer;
}