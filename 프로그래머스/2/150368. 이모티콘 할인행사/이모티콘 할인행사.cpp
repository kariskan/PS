#include <string>
#include <vector>

using namespace std;

vector<vector<int>> users;
vector<int> emoticons;

int maxSign, maxRes;

void get(vector<int> ratio) {

	int sign = 0, res = 0;

	int sum = 0;

	for (int i = 0; i < emoticons.size(); i++) {
		sum += emoticons[i] * (100 - ratio[i]) / 100;
	}

	for (int i = 0; i < users.size(); i++) {
		int userSum = 0;
		for (int j = 0; j < emoticons.size(); j++) {
			if (ratio[j] >= users[i][0]) {
				userSum += emoticons[j] * (100 - ratio[j]) / 100;
			}
		}
		if (userSum >= users[i][1]) {
			sign++;
		}
		else {
			res += userSum;
		}
	}

	if (maxSign < sign) {
		maxSign = sign;
		maxRes = res;
	}
	else if (maxSign == sign) {
		if (maxRes < res) {
			maxRes = res;
		}
	}
}

void go(int idx, vector<int> ratio) {
	get(ratio);
	if (idx >= ratio.size()) return;



	for (int j = 10; j <= 40; j += 10) {
		int k = ratio[idx];
		ratio[idx] = j;
		go(idx + 1, ratio);
		ratio[idx] = k;
	}

}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
	vector<int> answer;
	::users = users;
	::emoticons = emoticons;

	vector<int> ratio(emoticons.size(), 10);

	go(0, ratio);

	return { maxSign,maxRes };
}