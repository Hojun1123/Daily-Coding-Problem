#include <vector>
#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <unordered_map>
#include <map>
#include <cmath>
#include <deque>
#include <unordered_set>
using namespace std;
int C, N, Q;
unordered_set<string> us;
vector<int> v;
struct Trie {
	int isEnd;
	Trie* child[26];
	Trie() {
		isEnd = 0;
		for (int i = 0; i < 26; ++i) child[i] = NULL;
	}
	~Trie() {

	}

	void Insert(string& str, int index) {
		if (index == str.size()) {
			isEnd = 1;
			return;
		}
		int idx = str[index] - 'a';
		if (child[idx] == NULL) {
			child[idx] = new Trie();
		}
		child[idx]->Insert(str, index + 1);
	}

	void FindColor(string& str, int index) {
		if (isEnd) {
			v.push_back(index);
		}
		if (index == str.size()) {
			return;
		}
		int idx = str[index] - 'a';
		if (child[idx] == NULL) return;
		child[idx]->FindColor(str, index + 1);
	}
};
Trie color;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> C >> N;
	string input;
	for (int i = 0; i < C; ++i) {
		cin >> input;
		color.Insert(input, 0);
	}
	for (int i = 0; i < N; ++i) {
		cin >> input;
		us.insert(input);	//set에 넣음
	}
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		//query. 20000
		//색상 -> 닉네임.
		cin >> input;
		v.clear();
		color.FindColor(input, 0);
		//index ~ end
		int  r = 0;
		for (int k = 0; k < v.size(); ++k) {
			string curr = input.substr(v[k]);
			if (us.find(curr) != us.end()) {
				r = 1;
				break;
			}
		}
		cout << (r ? "Yes\n" : "No\n");
	}
	return 0;
}