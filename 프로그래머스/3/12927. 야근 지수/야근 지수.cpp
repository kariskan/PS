#include <string>
#include <vector>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;
    for(int i=0;i<works.size();i++){
        pq.push(works[i]);
    }
    while(!pq.empty()&&n){
        int a=pq.top();
        pq.pop();
        if(a>1){
            pq.push(a-1);
        }
        n--;
    }
    while(!pq.empty()){
        long long a=pq.top();
        pq.pop();
        answer+=a*a;
    }
    return answer;
}