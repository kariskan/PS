#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int t=1;
    for(;;t++){
        bool flag = false;
        int xCount=0, otherCount=0;
        for(int i=0;i<s.length();i++){
            if(s[0]==s[i]){
                xCount++;
            }else{
                otherCount++;
            }
            if(xCount==otherCount){
                s=s.substr(i+1);
                if (s==""){
                    return t;
                }
                flag = true;
                break;
            }
        }
        if (!flag) {
            break;
        }
    }
    
    return t;
}