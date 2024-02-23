#include <iostream>
#include<vector>
#include <queue>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer=0;
    priority_queue<int> p,q;
    for(int i=0;i<A.size();i++){
        q.push(A[i]);
        p.push(-B[i]);
    }
    while(!q.empty()){
        answer+=q.top()*-p.top();
        q.pop();
        p.pop();
    }
    return answer;
}