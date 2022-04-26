#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct point {
	int first;
	int second;
};
vector<point> gi, bo;
bool compare(const vector<int>& a, const vector<int>& b) {
	if (a[0] == b[0]) {
		if (a[1] == b[1]) {
			return a[2] < b[2];
		}
		return a[1] < b[1];
	}
	return a[0] < b[0];
}
bool checkGi(point bottom) {
	for (const point& p : gi) {
		if (bottom.first == p.first && bottom.second== p.second)return true;
	}
	return false;
}

bool checkBo(point left) {
	for (const point& p : bo) {
		if (left.first == p.first && left.second == p.second)return true;
	}
	return false;
}
void findGi(point bottom) {
	for (int i = 0; i < gi.size(); i++) {
		if (gi[i].first == bottom.first && gi[i].second == bottom.second) {
			gi.erase(gi.begin() + i);
			return;
		}
	}
}
void findBo(point left) {
	for (int i = 0; i < bo.size(); i++) {
		if (bo[i].first == left.first && bo[i].second == left.second) {
			bo.erase(bo.begin() + i);
			return;
		}
	}
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;
	for (int i = 0; i < build_frame.size(); i++) {
		int x = n - build_frame[i][1], y = build_frame[i][0], a = build_frame[i][2], b = build_frame[i][3];
		if (a == 0) { //기둥
			if (b == 0) { //삭제
				//위에 기둥이 있는데, 양옆에 보가 없는 경우
				//또는, 옆에 보가 하나 있는데 조건을 만족못할 경우
				if ((checkGi({ x - 1,y }) && !checkBo({ x - 1,y - 1 }) && !checkBo({ x - 1,y }))
					|| (checkBo({ x - 1,y - 1 }) && (!checkGi({ x,y - 1 }) && (!checkBo({ x - 1,y - 2 }) || !checkBo({ x - 1,y }))))
					|| (checkBo({ x - 1,y }) && (!checkGi({ x,y + 1 }) && (!checkBo({ x - 1,y - 1 }) || !checkBo({ x - 1,y + 1 }))))) {
					continue;
				}
				findGi({ x,y });
			}
			else { //설치
				if (x == n || checkBo({ x,y - 1 }) || checkBo({ x,y })
					|| checkGi({ x + 1,y })) {
					gi.push_back({ x,y });
				}
			}
		}
		else { //보
			if (b == 0) { //삭제
				//옆에 보가 있는데 보가 조건을 만족못할 경우
				if ((checkBo({ x,y - 1 }) && !checkGi({ x + 1,y - 1 }) && !checkGi({ x + 1,y }))
					|| (checkBo({ x,y + 1 }) && !checkGi({ x + 1,y + 1 }) && !checkGi({ x + 1,y + 2 }))
					|| (checkGi({ x,y }) && !checkBo({ x,y - 1 }) && !checkGi({ x + 1,y }))
					|| (checkGi({ x,y + 1 }) && !checkBo({ x,y + 1 }) && !checkGi({ x + 1,y + 1 }))) {
					continue;
				}
				findBo({ x,y });
			}
			else { //설치
				if (checkGi({ x + 1,y }) || checkGi({ x + 1,y + 1 })
					|| (checkBo({ x,y - 1 }) && checkBo({ x,y + 1 }))) {
					bo.push_back({ x,y });
				}
			}
		}
	}
	for (const point& p : gi) {
		answer.push_back({ p.second,n - p.first,0 });
	}
	for (const point& p : bo) {
		answer.push_back({ p.second,n - p.first,1 });
	}
	sort(answer.begin(), answer.end(), compare);
	return answer;
}