#include <string>
#include <vector>
#include <queue>
using namespace std;
priority_queue<int> maxq,minq;
vector<int> solution(vector<string> operations) {
    vector<int> answer;
    int siz=0;
    for(string op:operations){
        int num=stoi(op.substr(2));
        if(op[0]=='I'){
            maxq.push(num);
            minq.push(-num);
            siz++;
        }else{
            if(siz==0){
                continue;
            }
            if(num==1){
                maxq.pop();
            }else{
                minq.pop();
            }
            siz--;
        }
        if(siz==0){
            while(!maxq.empty()){
                maxq.pop();
            }
            while(!minq.empty()){
                minq.pop();
            }
        }
    }
    
    if(siz==0){
        return {0,0};
    }
    return {maxq.top(),-minq.top()};
}