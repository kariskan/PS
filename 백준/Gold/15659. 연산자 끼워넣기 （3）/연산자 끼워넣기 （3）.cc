#include <climits>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

int n, a[11], op[4], c;
int minAns = INT_MAX, maxAns = INT_MIN;

int calc(int a, int b, int c) {
    if (c == 0) {
        return a + b;
    }
    if (c == 1) {
        return a - b;
    }
    if (c == 2) {
        return a * b;
    }
    return a / b;
}

int process(vector<int> seq) {
    deque<int> st;
    vector<int> opst = seq;
    st.push_back(a[0]);
    int idx = 0;
    for (int i = 0; i < opst.size(); i++) {
        if (opst[i] == 2 || opst[i] == 3) {
            int res = calc(st.back(), a[i + idx + 1], opst[i]);
            st.pop_back();
            st.push_back(res);
            opst.erase(opst.begin() + i);
            i--;
            idx++;
        } else {
            st.push_back(a[i + idx + 1]);
        }
    }
    while (st.size() != 1) {
        int a = st.front();
        st.pop_front();
        int b = st.front();
        st.pop_front();

        int res = calc(a, b, opst.front());

        opst.erase(opst.begin());
        st.push_front(res);
    }
    return st[0];
}

void go(vector<int> o, vector<int> seq, int cnt) {
    if (cnt == n - 1) {
        int res = process(seq);
        minAns = min(minAns, res);
        maxAns = max(maxAns, res);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (o[i] < op[i]) {
            o[i]++;
            seq.push_back(i);
            go(o, seq, cnt + 1);
            seq.pop_back();
            o[i]--;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> op[0] >> op[1] >> op[2] >> op[3];
    vector<int> o(4);
    go(o, {}, 0);

    cout << maxAns << '\n' << minAns;
}