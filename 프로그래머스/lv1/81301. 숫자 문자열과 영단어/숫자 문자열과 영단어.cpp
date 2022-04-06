#include <string>
#include <vector>
#include <map>
using namespace std;
map <string, string> m = { {"zero","0"},{"one","1"},{"two","2"},{"three","3"},{"four","4"},{"five","5"},{"six","6"},{"seven","7"},{"eight","8"},{"nine","9"} };
int solution(string s) {
    int len = s.length();
    int idx = 0;
    string ans = "";
    string temp = "";
    for (int i = 0; i < len; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            ans += s[i];
        }
        else {
            temp += s[i];
            if (m.find(temp) != m.end()) {
                ans += m[temp];
                temp = "";
            }
        }
    }
    int answer = stoi(ans);
    return answer;
}