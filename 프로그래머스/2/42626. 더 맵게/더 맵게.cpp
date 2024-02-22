#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int> q;
    for(int i=0;i<scoville.size();i++){
        q.push(-scoville[i]);
    }
    while(q.size()>=2&&-q.top()<K){
        int f=-q.top();
        q.pop();
        int s=-q.top();
        q.pop();
        q.push(-(f+s*2));
        answer++;
    }
    return q.empty()||-q.top()<K?-1:answer;
}