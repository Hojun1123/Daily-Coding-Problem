#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;
struct TrieNode {
	int isWord = 0;
	map<string, TrieNode*> children;

	TrieNode() {
		isWord = false;
	}
	~TrieNode() {

	}

	void Insert(vector<string>& word, int index)
	{
		if (word.size() == index) {
			// 더 이상 문자가 없는 경우
			isWord = 1;
			return;
		}
		if (children.find(word[index]) == children.end()) {
			children[word[index]] = new TrieNode();
		}

		children[word[index]]->Insert(word, index + 1);
	}

	void dfs(int index) {
		for (auto& i : children) {
			for (int k = 0; k < index; ++k) {
				cout << "--";
			}
			cout << i.first << "\n";
			i.second->dfs(index + 1);
		}
	}

};
int N;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	TrieNode root;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int k;
		cin >> k;
		vector<string> arr;
		string a;
		for (int j = 0; j < k; ++j) {
			cin >> a;
			arr.push_back(a);
		}
		root.Insert(arr, 0);
	}
	root.dfs(0);
	return 0;
}
