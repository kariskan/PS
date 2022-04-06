#include <string>
#include <vector>
using namespace std;
int n(int num) {
	int cnt = 0;
	while (num) {
		cnt++;
		num /= 10;
	}
	return cnt;
}
int comp(string s, int unit) {
	int len = s.length();
	int res = 0;
	int j = 0;
	for (int i = 0; i < len; i++) {
		string temp = "";
		if (i + unit < len) {
			temp = s.substr(i, unit);
			int cnt = 0;
			while (s.substr(j, unit) == temp) {
				cnt++;
				j += unit;
			}
			res += min(unit * cnt, n(cnt) + unit);
			i = j - 1;
		}
		else {
			res += len - i;
			break;
		}
	}
	return res;
}

int solution(string s) {
	int answer = s.length();
	int len = s.length();
	for (int i = 1; i <= len / 2; i++) {
		answer = min(answer, comp(s, i));
	}
	return answer;
}