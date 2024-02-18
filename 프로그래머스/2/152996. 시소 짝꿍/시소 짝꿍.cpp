#include <string>
#include <vector>
#include <map>
using namespace std;
map<int,long long> ma;
long long solution(vector<int> weights) {
    long long answer = 0;
    for(int i=0;i<weights.size();i++){
        ma[weights[i]]++;
    }
    for(auto&i:ma){
        answer+=((i.second)*(i.second-1))/2;
        if((i.first*3)%2==0&&ma.find((i.first*3)/2)!=ma.end()){
            answer+=i.second*ma[(i.first*3)/2];
        }
        if((i.first*4)%2==0&&ma.find((i.first*4)/2)!=ma.end()){
            answer+=i.second*ma[(i.first*4)/2];
        }
        if((i.first*4)%3==0&&ma.find((i.first*4)/3)!=ma.end()){
            answer+=i.second*ma[(i.first*4)/3];
        }
    }
    return answer;
}