#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, int> ma;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    for(int i=0;i<keymap.size();i++){
        for(int j=0;j<keymap[i].length();j++){
            if(ma.find(keymap[i][j])==ma.end()||ma[keymap[i][j]]>j+1){
                ma[keymap[i][j]]=j+1;
            }
        }
    }
    for(string target:targets){
        int sum = 0;
        for(char a:target){
            if (ma.find(a)==ma.end()){
                sum=-1;
                break;
            }
            sum += ma[a];
        }
        answer.push_back(sum);
    }
    
    return answer;
}