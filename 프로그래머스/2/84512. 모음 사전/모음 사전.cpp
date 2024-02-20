#include <string>
#include <vector>

using namespace std;
string word;
int answer;
char w[5]={'A','E','I','O','U'};
int cnt;
void go(string now){
    if(word==now){
        answer=cnt;
        return;
    }
    if(now.length()==5){
        return;
    }
    for(int i=0;i<5;i++){
        cnt++;
        go(now+w[i]);
    }
}

int solution(string word) {
    ::word=word;
    go("");
    return answer;
}