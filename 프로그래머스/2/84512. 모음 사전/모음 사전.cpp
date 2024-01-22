#include <string>
#include <vector>

using namespace std;
string word;
int cnt=0;
bool ok=false;
void go(string s){
    if(s==word){
        ok=true;
        return;
    }
    if(s.length()==5){
        return;
    }
    cnt++;
    go(s+"A");
    if(ok){
        return;
    }
    cnt++;
    go(s+"E");
    if(ok){
        return;
    }
    cnt++;
    go(s+"I");
    if(ok){
        return;
    }
    cnt++;
    go(s+"O");
    if(ok){
        return;
    }
    cnt++;
    go(s+"U");
}

int solution(string word) {
    ::word=word;
    go("");
    return cnt;
}

int main(){
    solution("AAAAE");
}