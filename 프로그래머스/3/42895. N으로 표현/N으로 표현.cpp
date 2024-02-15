#include <string>
#include <vector>
#include <set>
using namespace std;
set<int> se[9];
int solution(int n, int number) {
    int r=0;
    for(int i=1;i<=8;i++){
        r=r*10+n;
        se[i].insert(r);
    }
    for(int i=1;i<=8;i++){
        for(int j=1;j<i;j++){
            for(auto&k:se[j]){
                for(auto&l:se[i-j]){
                    se[i].insert(k+l);
                    se[i].insert(k-l);
                    se[i].insert(k*l);
                    if(l!=0){
                        se[i].insert(k/l);
                    }
                }
            }
        }
        if(se[i].find(number)!=se[i].end()){
            return i;
        }
    }
    return -1;
}
int main(){
    solution(5,12);
}