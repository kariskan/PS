#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;
set<string> se;
map<string,int> ma;
vector<int> solution(vector<string> gems) {
    vector<int> answer={1,(int)gems.size()};
    
    for(int i=0;i<gems.size();i++){
        se.insert(gems[i]);
    }
    int left=0,right=0;
    ma[gems[0]]=1;
    while(right<gems.size()){
        while(ma.size()==se.size()){
            if(answer[1]-answer[0]>right-left){
                answer={left+1,right+1};
            }
            ma[gems[left]]--;
            if(ma[gems[left]]==0){
                ma.erase(gems[left]);
            }
            left++;
        }
        right++;
        if(right==gems.size()){
            break;
        }
        ma[gems[right]]++;
    }
    return answer;
}