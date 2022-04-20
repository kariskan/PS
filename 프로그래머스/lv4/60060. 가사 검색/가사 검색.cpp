#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct Trie {
	bool end;
	int count;
	Trie* node[26];

	Trie() {
		end = false;
		count = 0;
		for (int i = 0; i < 26; i++)node[i] = nullptr;
	}

	void insert(const char* str) {
		count++;
		if (*str == '\0') {
			end = true;
			return;
		}

		int pos = *str - 'a';
		if (node[pos] == nullptr)node[pos] = new Trie();
		node[pos]->insert(str + 1);
	}

	int find(const char* str) {
		if (*str == '?')return count;

		int pos = *str - 'a';
		if (node[pos] == nullptr)return 0;
		return node[pos]->find(str + 1);
	}
};

Trie* trie[10001], * reverseTrie[10001];

vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;
	int wordSize = words.size();
	for (int i = 0; i < wordSize; i++) {
		string s = words[i];
		int len = s.length();
		if (trie[len] == nullptr) {
			trie[len] = new Trie();
		}
		trie[len]->insert(s.c_str());

		reverse(s.begin(), s.end());
		if (reverseTrie[len] == nullptr)reverseTrie[len] = new Trie();
		reverseTrie[len]->insert(s.c_str());
	}

	map<string, int> m;
	int qSize = queries.size();
	for (int i = 0; i < qSize; i++) {
		string s = queries[i];
		if (m.count(s) == 0) {
			m[s] = i;
			int len = s.length();
			if (s[s.length() - 1] == '?') {
				if (trie[len] == nullptr)answer.push_back(0);
				else answer.push_back(trie[len]->find(s.c_str()));
			}
			else {
				reverse(s.begin(), s.end());
				if (reverseTrie[len] == nullptr)answer.push_back(0);
				else answer.push_back(reverseTrie[len]->find(s.c_str()));
			}
		}
		else answer.push_back(answer[m[s]]);
	}

	return answer;
}