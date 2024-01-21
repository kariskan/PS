#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
map<int,int> se;
int solution(int k, vector<int> tangerine) {
    int answer = 0;
    for(int i=0;i<tangerine.size();i++){
        se[tangerine[i]]++;
    }
    vector<int> v;
    for(auto&i:se){
        v.push_back(i.second);
    }
    sort(v.begin(),v.end());
    for(int i=v.size()-1;i>=0;i--){
        if(answer+v[i]>=k){
            return v.size()-i;
        }
        answer+=v[i];
    }
    return answer;
}