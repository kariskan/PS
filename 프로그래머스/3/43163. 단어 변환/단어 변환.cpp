#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool can(string s1,string s2){
    int cnt=0;
    for(int i=0;i<s1.length();i++){
        if(s1[i]!=s2[i]){
            cnt++;
        }
    }
    return cnt==1;
}
int map[51][51];
int solution(string begin, string target, vector<string> words) {
    words.push_back(begin);
    for(int i=0;i<words.size();i++){
        for(int j=0;j<words.size();j++){
            if(i==j){
                continue;
            }else{
                if(can(words[i],words[j])){
                    map[i][j]=1;
                }
            }
        }
    }
    for(int k=0;k<words.size();k++){
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words.size();j++){
                if(map[i][k]&&map[k][j]&&(map[i][j]==0||map[i][j]>map[i][k]+map[k][j])){
                    map[i][j]=map[i][k]+map[k][j];
                }
            }
        }
    }
    for(int i=0;i<words.size();i++){
        if(words[i]==target){
            return map[words.size()-1][i];
        }
    }
    return 0;
}