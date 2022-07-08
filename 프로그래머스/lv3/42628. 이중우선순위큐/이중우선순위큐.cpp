#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;
map<int, int> m;
priority_queue<int> maxQ;
priority_queue<int, vector<int>, greater<int>> minQ;
vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    for(string s:operations) {
        if(s[0]=='I'){
            int a = stoi(s.substr(2));
            minQ.push(a);
            maxQ.push(a);
            m[a]++;
        }
        else {
            if(s[2]=='1') { //최댓값 삭제
                while(!maxQ.empty() && m[maxQ.top()] == 0){
                    maxQ.pop();
                }
                if(!maxQ.empty()) {
                    m[maxQ.top()]--;
                    maxQ.pop();
                }
            }
            else{ //최솟값 삭제
                while(!minQ.empty() && m[minQ.top()] == 0){
                    minQ.pop();
                }
                if(!minQ.empty()) {
                    m[minQ.top()]--;
                    minQ.pop();
                }
            }
        }
    }
    while(!minQ.empty() && m[minQ.top()] == 0){
                    minQ.pop();
    }
    while(!maxQ.empty() && m[maxQ.top()] == 0){
                    maxQ.pop();
    }
    if(maxQ.empty() || minQ.empty()) return {0,0};
    return {maxQ.top(),minQ.top()};
}