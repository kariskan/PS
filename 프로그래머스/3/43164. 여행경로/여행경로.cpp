#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
vector<vector<string>> tickets;
map<string,vector<string>> ma;
vector<string> answer;
map<pair<string,string>,int> ma2;
bool flag;
void go(string now,vector<string> seq){
    if(seq.size()==tickets.size()+1){
        answer=seq;
        flag=true;
        return;
    }
    for(auto&i:ma[now]){
        if(ma2[{now,i}]){
            ma2[{now,i}]--;
            seq.push_back(i);
            go(i,seq);
            if(flag){
                return;
            }
            seq.pop_back();
            ma2[{now,i}]++;
        }
    }
}
vector<string> solution(vector<vector<string>> tickets) {
    ::tickets=tickets;
    for(int i=0;i<tickets.size();i++){
        ma[tickets[i][0]].push_back(tickets[i][1]);
        ma2[{tickets[i][0],tickets[i][1]}]++;
    }
    for(auto&i:ma){
        sort(i.second.begin(),i.second.end());
    }
    go("ICN",{"ICN"});
    return answer;
}