#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(string a, string b) {
	char first = b[0];
	char second = b[2];
	int num = b[4] - '0';
	char bigger = b[3];
	for (int i = 0; i < 8; i++) {
		if (first == a[i]) {
			for (int j = 0; j < 8; j++) {
				if (second == a[j]) {
					if (bigger == '=') {
						return abs(i - j) - 1 == num;
					}
					else if (bigger == '>') {
						return abs(i - j) - 1 > num;
					}
					else {
						return abs(i - j) - 1 < num;
					}
				}
			}
		}
	}

}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
	int answer = 0;
	string s = "ACFJMNRT";
	do {
		int ok = 0;
		for (string c : data) {
			if (!check(s, c)) {
				ok = 1;
				break;
			}
		}
		if (!ok) {
			answer++;
		}
	} while (next_permutation(s.begin(), s.end()));

	return answer;
}