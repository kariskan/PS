#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
vector<vector<int>> v;
map<int, int> m;
bool compare(const vector<int>& a, const vector<int>& b) {
    return a.size() < b.size();
}
vector<int> solution(string s) {
    vector<int> answer;
    int len = s.length();
    int vIdx = -1;
    string temp = "";
    vector<int> v2;
    for (int i = 1; i < len; i++) {
        if (s[i] == '{') {
            if (!v2.empty()) {
                v.push_back(v2);
                v2.clear();
            }
        }
        else if (s[i] >= '0' && s[i] <= '9') {
            temp += s[i];
        }
        else {
            if (temp.length()) {
                v2.push_back(stoi(temp));
                temp = "";
            }
        }
    }
    if(!v2.empty()) v.push_back(v2);
    sort(v.begin(), v.end(), compare);
    for (const vector<int>& a : v) {
        for (const int& b : a) {
            if (m.find(b) == m.end()) {
                answer.push_back(b);
                m[b] = 1;
            }
        }
    }
    return answer;
}