#include <string>
#include <vector>

using namespace std;
vector<vector<int>> users;
vector<int> emoticons,ratio;
vector<int> answer={0,0};
pair<int,int> get(){
    int plus=0,price=0;
    for(int i=0;i<users.size();i++){
        int sum=0;
        for(int j=0;j<emoticons.size();j++){
            if(users[i][0]<=ratio[j]){
                sum+=(emoticons[j]*(100-ratio[j]))/100;
            }
        }
        if(sum>=users[i][1]){
            plus++;
        }else{
            price+=sum;
        }
    }
    return {plus,price};
}
void go(int idx){
    if(idx>=emoticons.size()){
        pair<int,int>g=get();
        if(answer[0]<g.first||(answer[0]==g.first&&answer[1]<g.second)){
            answer={g.first,g.second};
        }
        return;
    }
    for(int i=10;i<=40;i+=10){
        ratio.push_back(i);
        go(idx+1);
        ratio.pop_back();
    }
}
vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    ::users=users;
    ::emoticons=emoticons;
    go(0);
    return answer;
}