#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

map<int,int> ma;
vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int,vector<int>,greater<int>> minq;
    priority_queue<int> maxq;
    for(string op:operations){
        char o=op[0];
        int d=stoi(op.substr(2));
        if(o=='I'){
            minq.push(d);
            maxq.push(d);
            ma[d]++;
        }else{
            if(d==1){
                while(!maxq.empty()&&ma[maxq.top()]==0){
                    maxq.pop();
                }
                if(!maxq.empty()){
                    ma[maxq.top()]--;
                    maxq.pop();
                }
            }else{
                while(!minq.empty()&&ma[minq.top()]==0){
                    minq.pop();
                }
                if(!minq.empty()){
                    ma[minq.top()]--;
                    minq.pop();
                }
            }
        }
    }
    while(!minq.empty()&&ma[minq.top()]==0){
        minq.pop();
    }
    while(!maxq.empty()&&ma[maxq.top()]==0){
        maxq.pop();
    }
    if(minq.empty()||maxq.empty()){
        return {0,0};
    }
    return {maxq.top(),minq.top()};
}