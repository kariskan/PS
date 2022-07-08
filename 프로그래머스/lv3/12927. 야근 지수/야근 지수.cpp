#include <string>
#include <vector>
#include <queue>
using namespace std;
priority_queue<long long> pq;
long long solution(int n, vector<int> works) {
    long long answer = 0;
    long long sum = 0;
    
    for(int w:works) pq.push(w);
    
    for(int i=0;i<n;i++){
        int t = pq.top();
        pq.pop();
        if(t == 0 || t == 1) pq.push(0);
        else pq.push(t - 1);
    }
    
    while(!pq.empty()) {
        answer += pq.top() * pq.top();
        pq.pop();
    }
    
    return answer;
}