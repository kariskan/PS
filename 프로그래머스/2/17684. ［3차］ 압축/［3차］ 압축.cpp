#include <string>
#include <vector>
#include <map>
using namespace std;
map<string,int> ma={{"",0}};
vector<int> solution(string msg) {
    vector<int> answer;
    for(int i=1;i<=26;i++){
        string s="";
        s+=i-1+'A';
        ma[s]=i;
    }
    int lastCnt=26;
    for(int i=0;i<msg.length();i++){
        string s="";
        int idx=i;
        while(i<msg.length()&&ma.find(s)!=ma.end()){
            s+=msg[idx];
            idx++;
        }
        idx--;
        answer.push_back(ma[s.substr(0,s.length()-1)]);
        ma[s]=++lastCnt;
        i=idx-1;
    }
    return answer;
}