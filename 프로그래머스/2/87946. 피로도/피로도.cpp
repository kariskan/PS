#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    vector<int> v;
    for(int i=0;i<dungeons.size();i++){
        v.push_back(i);
    }
    do{
        int now=k;
        bool flag=true;
        for(int i=0;i<v.size();i++){
            if(dungeons[v[i]][0]>now){
                answer=max(answer,i);
                flag=false;
                break;
            }
            now-=dungeons[v[i]][1];
        }
        if(flag){
            answer=dungeons.size();
        }
    }while(next_permutation(v.begin(),v.end()));
    return answer;
}