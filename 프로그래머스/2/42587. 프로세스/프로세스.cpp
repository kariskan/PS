#include <string>
#include <vector>
#include <queue>
using namespace std;
queue<pair<int,int>> v;
priority_queue<int> q;
int solution(vector<int> priorities, int location) {
    int answer = 1;
    for(int i=0;i<priorities.size();i++){
        v.push({i,priorities[i]});
        q.push(priorities[i]);
    }
    while(!v.empty()){
        while(v.front().second<q.top()){
            v.push(v.front());
            v.pop();
        }
        if(v.front().first==location){
            return answer;
        }
        v.pop();
        q.pop();
        answer++;
    }
    return answer;
}