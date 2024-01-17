#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool compare(char& a, char& b) {
    return a > b;
}

map<char, int> se;
string solution(string X, string Y) {
    string answer = "";
    for(int i=0;i<X.length();i++){
        se[X[i]]++;
    }
    for(int i=0;i<Y.length();i++){
        if(se[Y[i]]>=1){
            answer+=Y[i];
            se[Y[i]]--;
        }
    }
    if(answer.empty()){
        return "-1";
    }
    sort(answer.begin(),answer.end(),compare);
    if (answer[0]=='0'){
        return "0";
    }
    return answer;
}