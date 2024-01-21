#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    queue<int> q1,q2;
    long long q1sum=0,q2sum=0;
    for(int i=0;i<queue1.size();i++){
        q1.push(queue1[i]);
        q2.push(queue2[i]);
        q1sum+=queue1[i];
        q2sum+=queue2[i];
    }
    while(q1sum!=q2sum){
        if(q1sum>q2sum){
            int f = q1.front();
            q1sum-=f;
            q2sum+=f;
            q1.pop();
            q2.push(f);
        }else{
            int f = q2.front();
            q2sum-=f;
            q1sum+=f;
            q2.pop();
            q1.push(f);
        }
        answer++;
        if(answer>(q1.size()+q2.size())*2){
            return -1;
        }
    }
    return answer;
}