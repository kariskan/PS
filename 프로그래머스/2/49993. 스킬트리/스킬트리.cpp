#include <string>
#include <vector>
#include <set>
using namespace std;
int seq[26];
int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(int i=0;i<skill.length()-1;i++){
        seq[skill[i]-'A']=skill[i+1]-'A';
    }
    for(int i=0;i<26;i++){
        if(seq[i]){
            continue;
        }
        seq[i]=-1;
    }
    for(string tree:skill_trees){
        int in[26]={0,};
        for(int i=0;i<skill.length()-1;i++){
            in[skill[i+1]-'A']++;
        }
        bool flag=true;
        for(int i=0;i<tree.length();i++){
            if(in[tree[i]-'A']){
                flag=false;
                break;
            }
            if(seq[tree[i]-'A']!=-1){
                in[seq[tree[i]-'A']]--;
            }
        }
        if(flag){
            answer++;
        }
    }
    return answer;
}