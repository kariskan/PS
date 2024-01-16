#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    
    for(int i=2;i<=number;i++){
        int cnt = 0;
        for(int j=1;j*j<=i;j++){
            if(i%j==0){
                if (j*j==i){
                    cnt++;
                } else {
                    cnt+=2;
                }
            }
        }
        printf("%d\n", cnt);
        if(cnt>limit){
            answer+=power;
        }else{
            answer+=cnt;
        }
    }
    
    return answer + 1;
}