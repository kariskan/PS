#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer={1,(int)gems.size()};
    map<string,int> ma;
    for(int i=0;i<gems.size();i++){
        ma[gems[i]]++;
    }
    
    int cnt=ma.size(),left=0,right=0;
    ma.clear();
    ma[gems[0]]++;
    
    while(right<gems.size()){
        if(ma.size()>=cnt){
            ma[gems[left]]--;
            if(ma[gems[left]]==0){
                ma.erase(gems[left]);
            }
            if(answer[1]-answer[0]>right-left){
                answer={left+1,right+1};
            }
            left++;
        }else{
            right++;
            if(right==gems.size()){
                break;
            }
            ma[gems[right]]++;
        }
    }
    return answer;
}