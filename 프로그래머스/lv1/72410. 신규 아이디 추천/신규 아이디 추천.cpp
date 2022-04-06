#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
	int len = new_id.length();
	for (int i = 0; i < len; i++) {
		char c = new_id[i];
		if (c >= 'A' && c <= 'Z') {
			new_id[i] += 32;
		}
	}
	for (int i = 0; i < len; i++) {
		char c = new_id[i];
		if (!new_id.empty() && !((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || c == '-' || c == '_' || c == '.')) {
			new_id.erase(new_id.begin() + i);
			len--;
			i--;
		}
	}
	for (int i = 0; i < len - 1; i++) {
		char c = new_id[i];
		if (!new_id.empty() && c == '.' && new_id[i + 1] == '.') {
			new_id.erase(new_id.begin() + i + 1);
			len--;
			i--;
		}
	}
	if (!new_id.empty() && new_id[0] == '.') {
		new_id.erase(new_id.begin());
		len--;
	}
	if (!new_id.empty() && new_id[len - 1] == '.') {
		new_id.pop_back();
	}
	if (new_id.empty()) {
		new_id = "a";
	}
	if (new_id.size() >= 16) {
		while (new_id.size() >= 16) {
			new_id.pop_back();
		}
		while (new_id[new_id.length() - 1] == '.') {
			new_id.pop_back();
		}
	}
	if (new_id.size() <= 2) {
		char c = new_id[new_id.length() - 1];
		while (new_id.size() < 3) {
			new_id.push_back(c);
		}
	}


	return new_id;
}