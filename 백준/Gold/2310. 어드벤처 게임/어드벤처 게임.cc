#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n;

typedef struct room {
	char c;
	int money;
	vector<int> v;
};

vector<room> r;
bool ok = false;
int visit[1001];
void go(int rI, int m) {

	if (rI == n) {
		ok = true;
		return;
	}

	vector<int> temp = r[rI].v;
	for (int i = 0; i < temp.size(); i++) {
		if (!visit[temp[i]]) {
			if (r[temp[i]].c == 'E') {
				visit[temp[i]] = 1;
				go(temp[i], m);
			}
			else if (r[temp[i]].c == 'L') {
				visit[temp[i]] = 1;
				go(temp[i], m < r[temp[i]].money ? r[temp[i]].money : m);
			}
			else {
				if (m < r[temp[i]].money)continue;
				visit[temp[i]] = 1;
				go(temp[i], m - r[temp[i]].money);
			}
		}
	}
}

int main() {
	while (1) {
		cin >> n;
		if (!n)break;
		r.push_back({});
		for (int i = 0; i < n; i++) {
			char c;
			int money;
			cin >> c >> money;
			vector<int> temp;
			while (1) {
				int k; cin >> k;
				if (k == 0)break;
				temp.push_back(k);
			}
			r.push_back({ c,money,temp });
		}
		go(1, 0);
		if (ok)cout << "Yes\n";
		else cout << "No\n";
		ok = false;
		r.clear();
		memset(visit, 0, sizeof(visit));
	}
}