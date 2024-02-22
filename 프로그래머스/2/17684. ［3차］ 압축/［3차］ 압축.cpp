#include <string>
#include <vector>
#include <map>
using namespace std;
map<string,int> ma;
vector<int> solution(string msg) {
    vector<int> answer;
    for(int i=0;i<26;i++){
        string s(1,i+'A');
        ma[s]=i+1;
    }
    int last=26;
    for(int i=0;i<msg.length();i++){
        int idx=i;
        string s(1,msg[i]);
        while(ma.find(s)!=ma.end()){
            idx++;
            if(idx==msg.length()){
                break;
            }
            s+=msg[idx];
        }
        if(ma.find(s)==ma.end()){
            ma[s]=++last;
            answer.push_back(ma[s.substr(0,s.length()-1)]);
        }else{
            answer.push_back(ma[s]);
        }
        i=idx-1;
    }
    return answer;
}