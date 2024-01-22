#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

bool compare(pair<string,pair<int,int>>&i,pair<string,pair<int,int>>&j){
    return i.second.first<j.second.first;
}

int parse(string s){
    return stoi(s.substr(0,2))*60+stoi(s.substr(3));
}
vector<pair<string, pair<int, int>>> v;
vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    for(int i=0;i<plans.size();i++){
        int start=parse(plans[i][1]);
        int end=stoi(plans[i][2]);
        v.push_back({plans[i][0],{start,end}});
    }
    sort(v.begin(),v.end(),compare);

    stack<pair<string, int>> q;
    for(int i=0;i<v.size()-1;i++){
        int diff=v[i+1].second.first-v[i].second.first;
        if(diff<v[i].second.second){
            v[i].second.second-=diff;
            q.push({v[i].first,v[i].second.second});
            continue;
        }else{
            answer.push_back(v[i].first);
            diff-=v[i].second.second;
            while(!q.empty()&&diff){
                int mi=min(diff,q.top().second);
                q.top().second-=mi;
                diff-=mi;
                if(q.top().second==0){
                    answer.push_back(q.top().first);
                    q.pop();
                }
            }
        }
    }
    answer.push_back(v.back().first);
    while(!q.empty()){
        answer.push_back(q.top().first);
        q.pop();
    }

    return answer;
}