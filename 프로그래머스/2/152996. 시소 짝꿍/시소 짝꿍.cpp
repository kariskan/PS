#include <string>
#include <vector>
#include <map>
using namespace std;
map<int,long long> ma;
long long solution(vector<int> weights) {
    long long answer = 0;
    for(int weight:weights){
        ma[weight]++;
    }
    for(auto&i:ma){
        answer+=((i.second-1)*(i.second))/2; // 같은 거리
        answer+=i.second*ma[i.first*2];
        if(i.first%3==0){
            answer+=i.second*ma[(i.first*2)/3];
        }
        if(i.first%4==0){
            answer+=i.second*ma[(i.first*3)/4];
        }
    }
    return answer;
}