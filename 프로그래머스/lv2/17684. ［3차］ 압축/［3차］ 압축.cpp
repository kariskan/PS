#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<string, int> m;
vector<int> solution(string msg) {
    vector<int> answer;
    for (int i = 0; i < 26; i++) {
        string temp;
        temp += ('A' + i);
        m.insert({ temp,i + 1 });
    }
    int num = 27;
    for (int i = 0; i < msg.length(); i++) {
        string temp;
        temp += msg[i];
        string pre;
        int idx = i + 1;
        while (m.find(temp) != m.end()) {
            pre = temp;
            temp += msg[idx++];
        }
        answer.push_back(m[pre]);
        m[temp] = num++;
        i = idx - 2;
    }
    return answer;
}