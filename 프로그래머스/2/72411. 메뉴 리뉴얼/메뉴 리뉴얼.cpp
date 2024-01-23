#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
map<string,int> ma;
void go(string order, string now, int idx){
    if(idx>=order.length()){
        sort(now.begin(),now.end());
        ma[now]++;
        return;
    }
    go(order,now,idx+1);
    go(order,now+order[idx],idx+1);
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(int i=0;i<orders.size();i++){
        go(orders[i],"",0);
    }
    for(int courseCnt:course){
        vector<string> ans;
        int maxCnt=-1;
        for(auto&i:ma){
            if(i.first.length()!=courseCnt||i.second<2){
                continue;
            }
            if(i.second==maxCnt){
                ans.push_back(i.first);
            }else if(i.second>maxCnt){
                ans.clear();
                maxCnt=i.second;
                ans.push_back(i.first);
            }
        }
        for(auto&i:ans){
            answer.push_back(i);
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}