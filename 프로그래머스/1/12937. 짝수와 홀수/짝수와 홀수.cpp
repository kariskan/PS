#include <string>
#include <vector>

using namespace std;

string solution(int num) {
    return abs(num)%2==1?"Odd":"Even";
}