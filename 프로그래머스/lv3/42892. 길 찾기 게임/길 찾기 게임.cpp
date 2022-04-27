#include <string>
#include <vector>

using namespace std;
vector<vector<int>> answer;
vector<vector<int>> node;
int findLeft(int leftP, int rightP) {
	int sx = -1, sy = -1, idx = -1;
	for (int i = 0; i < node.size(); i++) {
		const vector<int>& v = node[i];
		if (rightP != -1)
			if(v[0] > node[rightP][0] || v[1] >= node[rightP][1])continue;
		if (leftP != -1)
			if(v[0] < node[leftP][0] || v[1] >= node[leftP][1])continue;
		if (sy == -1 || sy <= v[1]) {
			if (sy == v[1]) {
				if (sx > v[0])continue;
			}
			sx = v[0];
			sy = v[1];
			idx = i;
		}
	}
	return idx;
}
int findRight(int leftP, int rightP) {
	int sx = -1, sy = -1, idx = -1;
	for (int i = 0; i < node.size(); i++) {
		const vector<int>& v = node[i];
		if (leftP != -1)
			if(v[0] < node[leftP][0] || v[1] >= node[leftP][1])continue;
		if (rightP != -1)
			if(v[0] > node[rightP][0] || v[1] >= node[rightP][1])continue;
		if (sy == -1 || sy <= v[1]) {
			if (sy == v[1]) {
				if (sx < v[0])continue;
			}
			sx = v[0];
			sy = v[1];
			idx = i;
		}
	}
	return idx;
}

void preorder(int leftP, int rightP, int now) { //dir = 0 왼쪽, dir = 1 오른쪽

	answer[0].push_back(now + 1);

	int leftChild = findLeft(leftP, now);
	if (leftChild != -1) {
		preorder(leftP, now, leftChild);
	}

	int rightChild = findRight(now, rightP);
	if (rightChild != -1) {
		preorder(now, rightP, rightChild);
	}
}

void postorder(int leftP, int rightP, int now) { //dir = 0 왼쪽, dir = 1 오른쪽

	int leftChild = findLeft(leftP, now);
	if (leftChild != -1) {
		postorder(leftP, now, leftChild);
	}

	int rightChild = findRight(now, rightP);
	if (rightChild != -1) {
		postorder(now, rightP, rightChild);
	}

	answer[1].push_back(now + 1);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	answer.resize(2);
	node = nodeinfo;
	int x = -1, y = -1, idx = -1;
	for (int i = 0; i < nodeinfo.size(); i++) {
		const vector<int>& v = nodeinfo[i];
		if (v[1] > y) {
			x = v[0];
			y = v[1];
			idx = i;
		}
	}
	preorder(-1, -1, idx);
	postorder(-1, -1, idx);
	return answer;
}