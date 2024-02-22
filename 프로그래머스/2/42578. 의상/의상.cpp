#include <string>
#include <vector>
#include <map>
using namespace std;
map<string,int> ma;
int solution(vector<vector<string>> clothes) {
    int answer = 1;
    for(int i=0;i<clothes.size();i++){
        ma[clothes[i][1]]++;
    }
    for(auto&i:ma){
        answer*=(i.second+1);
    }
    return answer-1;
}