#include <stdio.h>
int visit[100001] = { 0, };
int airplane[100001] = { 0, };
int find(int n) {
	if (n == visit[n])return n;
	else return visit[n] = find(visit[n]);
}
void unite(int x, int y) {
	x = find(x);
	y = find(y);
	visit[x] = y;
}
int main() {
	int g, p;
	scanf("%d %d", &g, &p);
	for (int i = 1; i <= g; i++)
		visit[i] = i;
	int ans = 0;
	for (int i = 1; i <= p; i++) {
		scanf("%d", &airplane[i]);
	}
	for (int i = 1; i <= p; i++) {
		int emptycount = find(airplane[i]);
		if (emptycount == 0)break;
		else {
			ans++;
			unite(emptycount, emptycount - 1);
		}
	}
	printf("%d", ans);
}