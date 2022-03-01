#include <iostream>
#include <queue>
using namespace std;
int a, b;
queue<int> q;
int brk;
int visit[100001];
void run() {
	while (!q.empty()) {
		int k = q.front();
		q.pop();

		int temp = k * 2;
		if (temp <= 100000 && temp != k) {
			if (visit[temp] == -1 || visit[temp] > visit[k])
			{
				visit[temp] = visit[k];
				q.push(temp);
			}
		}
		if (temp == b)break;

		temp = k - 1;
		if (temp >= 0 && temp <= 100000) {
			if (visit[temp] == -1 || visit[temp] > visit[k] + 1)
			{
				visit[temp] = visit[k] + 1;
				q.push(temp);
			}
		}
		if (temp == b)break;
		temp = k + 1;
		if (temp >= 0 && temp <= 100000) {
			if (visit[temp] == -1 || visit[temp] > visit[k] + 1)
			{
				visit[temp] = visit[k] + 1;
				q.push(temp);
			}
		}
		if (temp == b)break;
		
	}
}
int main() {
	cin >> a >> b;
	q.push(a);
	for (int i = 0; i <= 100000; i++)visit[i] = -1;
	visit[a] = 1;
	run();
	cout << visit[b] - 1;
}