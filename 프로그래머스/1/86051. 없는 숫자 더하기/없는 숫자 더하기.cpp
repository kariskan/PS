#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = -1;
    
    int vis[10]={0,};
    for(int i=0;i<numbers.size();i++){
        vis[numbers[i]]=1;
    }
    for(int i=1;i<=9;i++){
        if(vis[i]==0){
            answer+=i;
        }
    }
    
    return answer+1;
}