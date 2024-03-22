#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;
int solution(vector<int> a) {
    int answer = 0;
    map<int,int>ma;
    for(int i=0;i<a.size();i++){
        ma[a[i]]++;
    }
    priority_queue<pair<int,int>> pq;
    for(auto&i:ma){
        pq.push({i.second,i.first});
    }
    while(!pq.empty()){
        if(pq.top().first*2<answer){
            break;
        }
        int k=pq.top().second;
        pq.pop();
        int cnt=0;
        for(int i=0;i<a.size()-1;i++){
            if((a[i]==k&&a[i+1]!=k)||(a[i]!=k&&a[i+1]==k)){
                cnt+=2;
                i++;
            }
        }
        answer=max(answer,cnt);
    }
    
    return answer;
}