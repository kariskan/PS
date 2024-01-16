#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    
    for(int i=0;i<=t.length()-p.length();i++){
        printf("%s\n",t.substr(i,p.length()).c_str());
        if(t.substr(i,p.length())<=p){
            answer++;
        }
    }
    
    return answer;
}