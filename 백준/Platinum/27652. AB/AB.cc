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
using namespace std;
int N;
struct Trie {
	int cnt;
	Trie* child[26];
	Trie() {
		cnt = 0;
		memset(child, 0, sizeof(child));
	}
	~Trie() {

	}

	void Insert(string &str, int index) {
		if (str.size() == index) {
			return;
		}
		int currIndex = str[index] - 'a';
		if (child[currIndex] == NULL) {
			child[currIndex] = new Trie();
		}
		child[currIndex]->cnt++;
		child[currIndex]->Insert(str, index + 1);
	}

	void Find(string& str, int index, int* carr) {
		carr[index] = cnt;
		if (str.size() == index) {
			return;
		}
		int currIndex = str[index] - 'a';
		if (child[currIndex] == NULL) return;
		child[currIndex]->Find(str, index + 1, carr);
	}

	void Delete(string& str, int index) {
		if (str.size() == index) {
			return;
		}
		int currIndex = str[index] - 'a';
		child[currIndex]->cnt--;
		child[currIndex]->Delete(str, index + 1);
	}
};
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//add, delete, find, add
	string input; char input2; string input3;
	Trie Aroot;
	Trie Broot;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> input;
		if (input == "find") {
			int ans = 0;
			cin >> input3;
			int acnt[1001];
			int bcnt[1001];
			string tmp = input3;
			reverse(tmp.begin(), tmp.end());
			memset(acnt, 0, sizeof(acnt));
			memset(bcnt, 0, sizeof(bcnt));
			Aroot.Find(input3, 0, acnt);
			Broot.Find(tmp, 0, bcnt);
			for (int k = 1; k < input3.size(); ++k) {
				//cout << acnt[k] << ", " << bcnt[input3.size() - k];
				ans += acnt[k] * bcnt[input3.size() - k];
			}
			cout << ans << "\n";
		}
		else {
			cin >> input2 >> input3;
			if (input == "add") {
				if (input2 == 'A') {
					Aroot.Insert(input3, 0);
				}
				else {
					reverse(input3.begin(), input3.end());
					Broot.Insert(input3, 0);
				}
			}
			else {
				if (input2 == 'A') {
					Aroot.Delete(input3, 0);
				}
				else {
					reverse(input3.begin(), input3.end());
					Broot.Delete(input3, 0);
				}
			}
		}
	}
	return 0;
}