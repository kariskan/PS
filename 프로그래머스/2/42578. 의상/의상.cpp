#include <string>
#include <vector>
#include <map>
using namespace std;
map<string,int>ma;
vector<int> v;
int answer;
void go(int sum,int idx){
    answer+=sum;
    if(idx>=v.size()){
        return;
    }
    for(int i=idx;i<v.size();i++){
        go(sum*v[i],i+1);
    }
}
int solution(vector<vector<string>> clothes) {
    for(vector<string> cloth:clothes){
        ma[cloth[1]]++;
    }
    for(auto&i:ma){
        v.push_back(i.second);
    }
    for(int i=0;i<v.size();i++){
        go(v[i],i+1);
        printf("%d\n", answer);
    }
    return answer;
}