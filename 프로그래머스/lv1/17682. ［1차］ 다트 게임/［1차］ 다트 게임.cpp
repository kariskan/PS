#include <string>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int num[3]={0,};
    char option[3] = {0,};
    int idx = -1;
    for(int i=0;i<dartResult.length();i++){
        char c = dartResult[i];
    if(c=='*'||c=='#'){
        option[idx] = c;
        if(c=='*'){
            if(idx>0){
                if(option[idx-1]=='#')num[idx-1]*=2;
                else num[idx-1]*=2;
            }
            num[idx]*=2;
        }
        else{
            num[idx]=-num[idx];
        }
    }
    else{
        if(c >= '0' && c <= '9'){
            if(i<dartResult.length()-1&&dartResult[i+1]=='0'){
                num[++idx]=10;
                i++;
                }
            else num[++idx] = (c - '0');
        }
        else {
            if(c=='S'){
                continue;
            }
            else if(c=='D'){
                num[idx] = num[idx]*num[idx];
            }
            else {
                num[idx] = num[idx]*num[idx]*num[idx];
            }
        }
    }
        printf("%d %d %d\n", num[0], num[1], num[2]);
    }
    return num[0]+num[1]+num[2];
}