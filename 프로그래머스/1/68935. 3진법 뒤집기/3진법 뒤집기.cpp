#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    string s = "";
    while(n){
        s+=to_string(n%3);
        n/=3;
    }
    int p = 1;
    for(int i=s.length()-1;i>=0;i--){
        answer+=p*(s[i]-'0');
        p*=3;
    }
    return answer;
}