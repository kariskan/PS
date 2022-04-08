#include <string>
#include <algorithm>
#include <stack>
using namespace std;
stack<long long> num;
stack<char> op;
int priority[6][3] = { //plus minus multiple, 수가 클수록 우선순위 높음
	{0,1,2},{0,2,1},
	{1,0,2},{1,2,0},
	{2,0,1},{2,1,0},
};

long long calc(long long a, long long b, char p) {
	if (p == '+')return a + b;
	if (p == '-')return a - b;
	return a * b;
}

int opToIdx(char p) {
	if (p == '+')return 0;
	if (p == '-')return 1;
	return 2;
}

long long solution(string expression) {
	long long answer = 0;

	for (int i = 0; i < 6; i++) {
		long long sum = 0;
		int len = expression.length();
		string temp = "";
		for (int j = 0; j < len; j++) {
			if (expression[j] == '+' || expression[j] == '-' || expression[j] == '*') {
				long long res = 0;
				num.push(stoll(temp));
				temp = "";
				while (!op.empty() && num.size() >= 2 && priority[i][opToIdx(expression[j])] <= priority[i][opToIdx(op.top())]) {
					long long b = num.top();
					num.pop();
					long long a = num.top();
					num.pop();
					res = calc(a, b, op.top());
					op.pop();
					num.push(res);
				}
				op.push(expression[j]);
			}
			else {
				temp += expression[j];
			}
		}
		long long res = 0;
		num.push(stoll(temp));
		while (!op.empty()) {
			long long b = num.top();
			num.pop();
			long long a = num.top();
			num.pop();
			res = calc(a, b, op.top());
			op.pop();
			num.push(res);
		}
		answer = max(answer, abs(num.top()));
	}
	return answer;
}