#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -2;
    long long sum1=0,sum2=0;
    queue<int> q1,q2;
    for(int i=0;i<queue1.size();i++){
        sum1+=queue1[i];
        sum2+=queue2[i];
        q1.push(queue1[i]);
        q2.push(queue2[i]);
    }
    
    int cnt=0;
    while(cnt<=(q1.size()+q2.size())*2){
        if(sum1<sum2){
            int front=q2.front();
            q2.pop();
            q1.push(front);
            sum2-=front;
            sum1+=front;
        }else if(sum2<sum1){
            int front=q1.front();
            q1.pop();
            q2.push(front);
            sum1-=front;
            sum2+=front;
        }else{
            return cnt;
        }
        cnt++;
    }
    
    return -1;
}