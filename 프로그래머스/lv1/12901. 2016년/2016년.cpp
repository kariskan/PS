#include <string>
#include <vector>

using namespace std;
int month[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
string day[7] = {"FRI","SAT","SUN","MON","TUE","WED","THU"};
string solution(int a, int b) {
    string answer = "";
    int sum = 0;
    for(int i=1;i<a;i++){
        sum += month[i];
    }
    sum += b - 1;
    
    return day[sum%7];
}