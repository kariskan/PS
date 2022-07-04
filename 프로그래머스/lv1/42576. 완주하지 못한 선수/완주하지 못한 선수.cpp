#include <string>
#include <vector>
#include <map>
using namespace std;
map<string, int> s;
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    for(string p:completion) {
        s[p]++;
    }
    for(string p:participant) {
        s[p]--;
    }
    for(auto i:s){
        if(i.second<0)return i.first;
    }
}