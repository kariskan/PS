#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

double getGrade(string s) {
    if (s == "A+") return 4.5;
    if (s == "A0") return 4.0;
    if (s == "B+") return 3.5;
    if (s == "B0") return 3.0;
    if (s == "C+") return 2.5;
    if (s == "C0") return 2.0;
    if (s == "D+") return 1.5;
    if (s == "D0") return 1.0;
    return 0.0;
}

int main() {
    double totalCnt = 0, totalSum = 0;

    for (int i = 0; i < 20; i++) {
        string s1, s3;
        double s2;

        cin >> s1 >> s2 >> s3;

        if (s3 == "P") {
            continue;
        }

        totalCnt += s2;
        totalSum += s2 * getGrade(s3);
    }
	
	printf("%.6lf", totalSum / totalCnt);
}