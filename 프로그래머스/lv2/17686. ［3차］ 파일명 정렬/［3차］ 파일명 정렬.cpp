#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> files;
vector<string> convert(string s) {
    vector<string> res;
    string temp = "";
    int flag = 0;
    for (int i = 0; i < s.length(); i++) {
        if (!flag && s[i] >= '0' && s[i] <= '9') {
            res.push_back(temp);
            temp = "";
            flag = 1;
        }
        else if (flag == 1 && !(s[i] >= '0' && s[i] <= '9')) {
            res.push_back(temp);
            temp = "";
            flag = 2;
            return res;
        }
        if (s[i] >= 'A' && s[i] <= 'Z')s[i] += 32;
        temp += s[i];
    }
    if (temp != "") res.push_back(temp);
    return res;
}
bool compare(string s1, string s2) {
    vector<string> v1 = convert(s1);
    vector<string> v2 = convert(s2);
    if (v1[0] == v2[0]) {
        if (stoi(v1[1]) == stoi(v2[1])) {
            for (string s : files) {
                if (s == s1)return true;
                else return false;
            }
        }
        return stoi(v1[1]) < stoi(v2[1]);
    }
    return v1[0] < v2[0];
}
vector<string> solution(vector<string> files) {
    ::files = files;
    for (string s : files) {
        convert(s);
    }
    stable_sort(files.begin(), files.end(), compare);
    return files;
}