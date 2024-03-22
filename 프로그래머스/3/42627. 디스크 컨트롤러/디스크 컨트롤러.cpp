#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(),jobs.end());
    int t=0,idx=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    while(idx<jobs.size()||!pq.empty()){
        if(idx<jobs.size()&&pq.empty()&&jobs[idx][0]>t){
            t=jobs[idx][0];
        }
        while(idx<jobs.size()&&jobs[idx][0]<=t){
            pq.push({jobs[idx][1],jobs[idx][0]});
            idx++;
        }
        answer+=t+pq.top().first-pq.top().second;
        t+=pq.top().first;
        pq.pop();
    }
    return answer/jobs.size();
}