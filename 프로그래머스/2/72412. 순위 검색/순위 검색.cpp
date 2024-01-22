#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> parse(string s) {
    stringstream ss(s);
    string temp;
    vector<string> v;
    while (getline(ss, temp, ' ')) {
        v.push_back(temp);
    }
    return v;
}

map<string, vector<int>> ma;

void go(int idx, string now, vector<string> infos, int score) {
    if (idx >= 4) {
        ma[now].push_back(score);
        return;
    }
    go(idx + 1, now, infos, score);
    go(idx + 1, now + infos[idx], infos, score);
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    for (int i = 0; i < info.size(); i++) {
        vector<string> infos = parse(info[i]);
        go(0, "", infos, stoi(infos[4]));
    }
    for (auto &i: ma) {
        sort(i.second.begin(), i.second.end());
    }
    for (int i = 0; i < query.size(); i++) {
        vector<string> queries = parse(query[i]);
        string q = "";
        for (int j = 0; j <= 6; j += 2) {
            if (queries[j] == "-") {
                continue;
            }
            q += queries[j];
        }
        vector<int> v = ma[q];
        int l = 0, r = v.size() - 1;
        int idx = -1;
        while (l <= r) {
            int mid = (l + r) / 2;

            if (v[mid] >= stoi(queries[7])) {
                r = mid - 1;
                idx = mid;
            } else {
                l = mid + 1;
            }
        }
        if (idx == -1) {
            answer.push_back(0);
        } else {
            answer.push_back(v.size() - idx);
        }
    }
    return answer;
}

int main() {
    solution({"java backend junior pizza 150", "python frontend senior chicken 210",
              "python frontend senior chicken 150", "cpp backend senior pizza 260", "java backend junior chicken 80",
              "python backend senior chicken 50"},
             {"java and backend and junior and pizza 100", "python and frontend and senior and chicken 200",
              "cpp and - and senior and pizza 250", "- and backend and senior and - 150",
              "- and - and - and chicken 100", "- and - and - and - 150"});
}