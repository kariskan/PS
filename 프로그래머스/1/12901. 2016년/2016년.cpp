#include <string>
#include <vector>

using namespace std;
int day[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
string aa[7]={"THU","FRI","SAT","SUN","MON","TUE","WED"};
string solution(int a, int b) {
    int d = 0;
    for(int i=0;i<a;i++){
        d+=day[i];
    }
    d+=b;
    return aa[d%7];
}