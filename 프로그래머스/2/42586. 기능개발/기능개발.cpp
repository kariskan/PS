#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int>q;
    for(int i=0;i<progresses.size();i++){
        q.push((99-progresses[i]+speeds[i])/speeds[i]);
    }
    int time=0;
    while(!q.empty()){
        time=q.front();
        int t=0;
        while(!q.empty()&&time>=q.front()){
            q.pop();
            t++;
        }
        answer.push_back(t);
    }
    return answer;
}