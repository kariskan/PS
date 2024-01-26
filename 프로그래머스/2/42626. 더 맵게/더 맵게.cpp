#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i=0;i<scoville.size();i++){
        q.push(scoville[i]);
    }
    while(q.size()>=2&&q.top()<K){
        int first=q.top();
        q.pop();
        int second=q.top();
        q.pop();
        q.push(first+second*2);
        answer++;
    }
    return q.top()<K?-1:answer;
}