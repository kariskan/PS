#include <string>
#include <vector>

using namespace std;

int pos[26];

vector<int> solution(string s) {
    vector<int> answer;
    for(int i=0;i<26;i++){
        pos[i]=-1;
    }
    for(int i=0;i<s.length();i++){
        if(pos[s[i]-'a']==-1){
            answer.push_back(-1);
        }else{
            answer.push_back(i-pos[s[i]-'a']);
        }
        pos[s[i]-'a']=i;
    }
    
    return answer;
}