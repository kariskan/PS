#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    for(int i=0;i<progresses.size();i++){
        q.push((99+speeds[i]-progresses[i])/speeds[i]);
    }
    while(!q.empty()){
        int day = q.front(),cnt=0;
        while(!q.empty()&&q.front()<=day){
            q.pop();
            cnt++;
        }
        answer.push_back(cnt);
    }
    return answer;
}