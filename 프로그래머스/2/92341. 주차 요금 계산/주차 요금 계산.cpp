#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <climits>
using namespace std;
vector<string> parse(string s){
    stringstream ss(s);
    vector<string> v;
    string temp;
    while(getline(ss,temp,' ')){
        v.push_back(temp);
    }
    return v;
}
int toTime(string s){
    return stoi(s.substr(0,2))*60+stoi(s.substr(3));
}
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string,int> ma,ans;
    for(int i=0;i<records.size();i++){
        vector<string> p=parse(records[i]);
        int time=toTime(p[0]);
        if(p[2]=="IN"){
            ma[p[1]]=time;
        }else{
            ans[p[1]]+=time-ma[p[1]];
            ma.erase(p[1]);
        }
    }
    for(auto&i:ma){
        ans[i.first]+=toTime("23:59")-i.second;
    }
    for(auto&i:ans){
        if(i.second>=fees[0]){
            i.second=fees[1]+((i.second-fees[0]+fees[2]-1)/fees[2])*fees[3];
        }else{
            i.second=fees[1];
        }
        answer.push_back(i.second);
    }
    return answer;
}