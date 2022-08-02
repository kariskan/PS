#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int main() {
	while (1) {
		vector<string> inp;
		while (1) {
			string s; cin >> s;
			if (s == "NUM") {
				long long num; cin >> num;
				string t = s + " " + to_string(num);
				inp.push_back(t);
			}
			else {
				if (s == "QUIT")return 0;
				if (s == "END")break;
				inp.push_back(s);
			}
		}
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			long long num; cin >> num;
			stack<long long> st;
			st.push(num);
			int ok = 1;
			for (string& s : inp) {
				if (s.substr(0, 3) == "NUM") {
					st.push(stoi(s.substr(4)));
				}
				else {
					if (st.empty()) {
						ok = 0;
						break;
					}
					if (s == "POP") {
						st.pop();
					}
					else if (s == "INV") {
						long long num = st.top();
						st.pop();
						st.push(-num);
					}
					else if (s == "DUP") {
						st.push(st.top());
					}
					else {
						if (st.size() < 2) {
							ok = 0;
							break;
						}
						long long first = st.top(); st.pop();
						long long second = st.top(); st.pop();
						if (s == "SWP") {
							st.push(first);
							st.push(second);
						}
						else if (s == "ADD") {
							st.push(first + second);
						}
						else if (s == "SUB") {
							st.push(second - first);
						}
						else if (s == "MUL") {
							st.push(first * second);
						}
						else if (s == "DIV") {
							if (first == 0) {
								ok = 0;
								break;
							}
							long long p = abs(second) / abs(first);
							if ((second < 0 && first > 0) || (second > 0 && first < 0)) {
								st.push(-p);
							}
							else st.push(p);
						}
						else if (s == "MOD") {
							if (first == 0) {
								ok = 0;
								break;
							}
							long long p = abs(second) % abs(first);
							if (second < 0) st.push(-p);
							else st.push(p);
						}
					}
				}
				if (!st.empty() && (st.top() > 1000000000 || st.top() < -1000000000)) {
					ok = 0;
					break;
				}
			}
			if (!ok || st.size() != 1)cout << "ERROR\n";
			else cout << st.top() << '\n';
		}
		cout << '\n';
	}
}