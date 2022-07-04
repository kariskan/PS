#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n;
bool compare(string& s1, string& s2) {
    if(s1[n] == s2[n]) return s1 < s2;
    return s1[n] < s2[n];
}
vector<string> solution(vector<string> strings, int n) {
    ::n = n;
    sort(strings.begin(), strings.end(), compare);
    return strings;
}