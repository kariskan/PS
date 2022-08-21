#include <iostream>
#define MAX 100001
using namespace std;

int N, M, ans;
int parent[MAX];

int find_parent(int a) {
    if (a == parent[a]) return a;
    return parent[a] = find_parent(parent[a]);
}

void make_parent(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    if (a != b)parent[a] = b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;

    for (int i = 1; i < MAX; i++) parent[i] = i;

    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        if (find_parent(a) != find_parent(b)) {
            make_parent(a, b);
        }
        else ans++; // 부모가 같은 경우(사이클이 생김) - 떼어내야 한다.
    }

    for (int i = 1; i <= N; i++) {  // 부모가 자기 자신인 경우 - 하나로 합쳐야 한다.
        if (i == find_parent(i)) ans++;
    }

    cout << ans - 1; // 바로 위에서 루트 노드도 합친경우를 빼준다.
}
