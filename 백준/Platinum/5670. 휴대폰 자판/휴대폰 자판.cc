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
// 휴대폰에서 길이가 P인 영단어는 P번 버튼을 눌러야 함
// 사전 내에서 가능한 다음 글자가 하나뿐이면 글자를 버튼 없이 자동으로 입력해줌
// 첫번째 글자는 무조건 누름
//
int T;
int N;
//소문자만, N은 10만개 이하, 1~80글자
string arr[100000];
double s = 0;
struct Trie {
	int isEnd;
	Trie* child[26];
	int childCnt;
	Trie() {
		isEnd = 0;
		childCnt = 0;
		for (int i = 0; i < 26; ++i) child[i] = NULL;
	}
	~Trie() {
		for (int i = 0; i < 26; ++i) {
			delete child[i];
		}
	}

	void Insert(string& str, int index)
	{
		if (index == str.size()) {
			isEnd = 1;
			return;
		}
		int ch = str[index] - 'a';
		if (child[ch] == NULL) {
			childCnt++;

			
			child[ch] = new Trie();
		}
		child[ch]->Insert(str, index + 1);
	}

	int Find(string& str, int index, int cnt)
	{
		if (index == str.size()) {
			s += cnt;
			return isEnd;
		}
		int ch = str[index] - 'a';
		if (child[ch] == NULL) return 0;
		else {
			if (index == 0 || isEnd || childCnt > 1) {
				//cout << str[index] << " ";
				return child[ch]->Find(str, index + 1, cnt + 1);
			}
			else {
				//cout << str[index] << ", ";
				return child[ch]->Find(str, index + 1, cnt);
			}
		}
	}
};
void solve()
{
	Trie root;
	string inp;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
		root.Insert(arr[i], 0);
	}
	s = (double)0.0;
	for (int i = 0; i < N; ++i) {
		root.Find(arr[i], 0, 0);
	}
	double ret = round((s / (double)N) * 100.0) / 100.0;
	cout << ret <<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(2);
	cout << fixed;
	while (cin >> N) {
		solve();
	}
	return 0;
}
