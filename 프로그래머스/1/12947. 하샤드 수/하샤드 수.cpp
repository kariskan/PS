#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int y = x,cnt=0;
    while(y){
        cnt+=y%10;
        y/=10;
    }
    return x%cnt==0;
}