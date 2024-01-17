#include <string>
#include <sstream>
#include <map>
using namespace std;

map<char, int> optionMap={
    {' ',1},
    {'*',2},
    {'#',-1}
};

int getT(char option, char preOption){
    if(preOption=='#'){
        return optionMap[option];
    }
    return optionMap[option]*optionMap[preOption];
}

int solution(string dart) {
    int answer = 0;
    
    char preOption=' ';
    for(int i=dart.length()-1;i>=0;i--){
        int score;
        char bonus, option=' ';
        if(dart[i]=='#'||dart[i]=='*'){
            option=dart[i];
            if(i>=3&&dart[i-2]=='0'&&dart[i-3]=='1'){
                score=10;
            }else{
                score=dart[i-2]-'0';
            }
            bonus=dart[i-1];
            i-=2;
            if(score==10){
                i--;
            }
        }else {
            if(i>=2&&dart[i-1]=='0'&&dart[i-2]=='1'){
                score=10;
            }else{
                score=dart[i-1]-'0';
            }
            bonus=dart[i];
            i--;
            if(score==10){
                i--;
            }
        }
        int t=getT(option,preOption);
        if(bonus=='S'){
            t*=score;
        }else if(bonus=='D'){
            t*=score*score;
        }else{
            t*=score*score*score;
        }
        answer+=t;
        preOption=option;
        printf("%d %c %c\n", t, bonus, option);
    }
    
    return answer;
}