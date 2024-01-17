#include <string>
#include <vector>
#include <map>
using namespace std;
map<string,int> c;
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    for(int i=0;i<participant.size();i++){
        c[participant[i]]++;
    }
    for(int i=0;i<completion.size();i++){
        c[completion[i]]--;
    }
    for(auto&i:c){
        if(i.second!=0){
            return i.first;
        }
    }
    
    return answer;
}