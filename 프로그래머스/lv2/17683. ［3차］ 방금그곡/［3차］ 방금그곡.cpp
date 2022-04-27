#include <string>
#include <vector>
#include <sstream>
using namespace std;
vector<string> v;
vector<string> convert(string s) {
    stringstream ss(s);
    string temp = "";
    vector<string> res;
    while (getline(ss, temp, ',')) {
        res.push_back(temp);
    }
    return res;
}
int stringToTime(string s) {
    return 60 * stoi(s.substr(0, 2)) + stoi(s.substr(3));
}
bool check(string m, vector<string> t) {
    for (int i = 0; i < t.size(); i++) {
        string temp = "";
        for (int j = i; j < t.size(); j++) {
            temp.append(t[j]);
            if (m == temp)return true;
        }
    }
    return false;
}
string solution(string m, vector<string> musicinfos) {
    string answer = "";
    int playTime = 0;
    for (string music : musicinfos) {
        vector<string>c = convert(music);
        int start = stringToTime(c[0]);
        int end = stringToTime(c[1]);
        vector<string> t;
        string inp = "";
        int idx = 0;
        for (int i = start; i < end; i++) {
            inp = "";
            inp += c[3][idx];
            if (idx < c[3].length() - 1 && c[3][idx + 1] == '#') {
                inp += c[3][idx + 1];
                idx = (idx + 2) % c[3].length();
            }
            else idx = (idx + 1) % c[3].length();
            t.push_back(inp);
        }
        if (check(m, t) && playTime < end - start) {
            playTime = end - start;
            answer = c[2];
        }
    }
    if (answer == "")answer = "(None)";
    return answer;
}