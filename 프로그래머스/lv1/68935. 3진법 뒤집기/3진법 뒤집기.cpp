#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    string s = "";
    while(n) {
        s += (n%3 + '0');
        if(n==3){
            s+='1';
            break;
        }
        n/=3;
    }
    int t = 1;
    printf("%s", s.c_str());
    for(int i=s.length() - 1;i>=0;i--){
        answer += t*(s[i]-'0');
        t*=3;
    }
    return answer;
}