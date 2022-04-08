#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
vector<int> inf[3][2][2][2];
int leng[4] = { 2,1,1,1 };
vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;
	int infoLen = info.size();
	for (int i = 0; i < infoLen; i++) {
		stringstream ss(info[i]);
		string temp;
		vector<string> v;
		while (getline(ss, temp, ' ')) {
			if (temp == "and")continue;
			v.push_back(temp);
		}
		int i1, i2, i3, i4;
		for (string k : v) {
			if (k == "cpp")i1 = 0;
			else if (k == "java")i1 = 1;
			else if (k == "python")i1 = 2;
			else if (k == "frontend")i2 = 0;
			else if (k == "backend")i2 = 1;
			else if (k == "junior")i3 = 0;
			else if (k == "senior")i3 = 1;
			else if (k == "pizza")i4 = 0;
			else if (k == "chicken")i4 = 1;
			else inf[i1][i2][i3][i4].push_back(stoi(k));
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				for (int l = 0; l < 2; l++) {
					sort(inf[i][j][k][l].begin(), inf[i][j][k][l].end());
				}
			}
		}
	}
	int qSize = query.size();
	for (int j = 0; j < qSize; j++) {
		stringstream ss(query[j]);
		string temp;
		vector<string> quer;
		while (getline(ss, temp, ' ')) {
			if (temp == "and")continue;
			quer.push_back(temp);
		}
		int idx[4] = { 0, };
		for (int i = 0; i < 4; i++) {
			if (quer[i] == "-") {
				idx[i] = -1;
			}
			else {
				if (quer[i] == "cpp")idx[i] = 0;
				else if (quer[i] == "java")idx[i] = 1;
				else if (quer[i] == "python")idx[i] = 2;
				else if (quer[i] == "frontend")idx[i] = 0;
				else if (quer[i] == "backend")idx[i] = 1;
				else if (quer[i] == "junior")idx[i] = 0;
				else if (quer[i] == "senior")idx[i] = 1;
				else if (quer[i] == "pizza")idx[i] = 0;
				else if (quer[i] == "chicken")idx[i] = 1;
			}
		}
		int i1s = idx[0] == -1 ? 0 : idx[0];
		int i2s = idx[1] == -1 ? 0 : idx[1];
		int i3s = idx[2] == -1 ? 0 : idx[2];
		int i4s = idx[3] == -1 ? 0 : idx[3];
		int i1e = idx[0] == -1 ? leng[0] : idx[0];
		int i2e = idx[1] == -1 ? leng[1] : idx[1];
		int i3e = idx[2] == -1 ? leng[2] : idx[2];
		int i4e = idx[3] == -1 ? leng[3] : idx[3];
		int cnt = 0;
		for (int i1 = i1s; i1 <= i1e; i1++) {
			for (int i2 = i2s; i2 <= i2e; i2++) {
				for (int i3 = i3s; i3 <= i3e; i3++) {
					for (int i4 = i4s; i4 <= i4e; i4++) {
						if (!inf[i1][i2][i3][i4].empty()) {
							int infSize = inf[i1][i2][i3][i4].size();
							int start = 0, end = infSize - 1;
							while (start <= end) {
								int mid = (start + end) / 2;
								if (inf[i1][i2][i3][i4][mid] >= stoi(quer[4])) {
									end = mid - 1;
								}
								else {
									start = mid + 1;
								}
							}
							cnt += infSize - start;
						}
					}
				}
			}
		}
		answer.push_back(cnt);
	}
	return answer;
}