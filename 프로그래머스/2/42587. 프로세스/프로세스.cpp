#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int,int>> q;
    priority_queue<int> pq;
    for(int i=0;i<priorities.size();i++){
        q.push({priorities[i],i});
        pq.push(priorities[i]);
    }
    int i=1;
    while(1){
        while(q.front().first!=pq.top()){
            pair<int,int> a=q.front();
            q.pop();
            q.push(a);
        }
        pair<int,int> a=q.front();
        q.pop();
        pq.pop();
        if(a.second==location){
            return i;
        }
        i++;
    }
    return answer;
}