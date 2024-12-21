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
using namespace std;
int N;
struct Node {
	int index;
	int length;
	bool operator<(Node o) const {
		return length < o.length;
	}
};
Node arr[1000];
vector<string> ans;
struct Trie {
	int isEnd;
	Trie* bf[2];
	Trie() {
		isEnd = 0;
		bf[0] = NULL;
		bf[1] = NULL;
	}
	~Trie() {
	}

	int Find(int len, string curr, int depth)
	{
		if (isEnd) return 0;
		if (len == depth) {
			//cout << curr << "\n";
			ans.push_back(curr);
			isEnd = 1;
			return 1;
		}
		if (bf[0] == NULL) {
			bf[0] = new Trie();
		}
		int ret = bf[0]->Find(len, curr + '0', depth + 1);
		if (ret) return ret;
		if (bf[1] == NULL) {
			bf[1] = new Trie();
		}
		return bf[1]->Find(len, curr + '1', depth + 1);
	}
};
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) { 
		cin >> arr[i].length;
		arr[i].index = i;
	}
	sort(arr, arr + N);
	Trie root;
	for (int i = 0; i < N; ++i) {
		int ret = root.Find(arr[i].length, "", 0);
		if (ret == 0) {
			cout << -1;
			return 0;
		}
	}
	string *ptr[1000];
	for (int i = 0; i < N; ++i) {
		ptr[arr[i].index] = &ans[i];
	}
	cout << "1\n";
	for (int i = 0; i < N; ++i) {
		cout << *ptr[i] << "\n";
	}
	return 0;
}
