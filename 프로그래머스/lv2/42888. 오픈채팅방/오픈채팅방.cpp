#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
using namespace std;
map<string, string> se;
vector<string> solution(vector<string> record) {
	vector<string> answer;
	for (string s : record) {
		istringstream ss(s);
		string stringBuffer;
		vector<string> x;
		while (getline(ss, stringBuffer, ' ')) {
			x.push_back(stringBuffer);
		}
		if (x[0] == "Enter" || x[0] == "Change") {
			se[x[1]] = x[2];
		}
	}
	for (string s : record) {
		istringstream ss(s);
		string stringBuffer;
		vector<string> x;
		while (getline(ss, stringBuffer, ' ')) {
			x.push_back(stringBuffer);
		}
		string t = "";
		if (x[0] == "Enter") {
			t += se[x[1]] + "님이 들어왔습니다.";
		}
		else if (x[0] == "Leave") {
			t += se[x[1]] + "님이 나갔습니다.";
		}
		else continue;
		answer.push_back(t);
	}
	return answer;
}