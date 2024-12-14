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
using namespace std;
int N, K;
vector<int> arr;
int ans = 0;
void bt(int index, int curr, int pick) {
	if (pick == K) {
		int cnt = 0;
		for (int i = 0; i < arr.size(); ++i) {
			cnt += (arr[i] & curr) == arr[i];
		}
		ans = max(ans, cnt);
		return;
	}
	if (index == 26) return;
	if (index == 'N' - 'A' || index == 0 || index == 'T' - 'A' ||
		index == 'C' - 'A' || index == 'I' - 'A') {
		bt(index + 1, curr, pick);
	}
	else {
		bt(index + 1, curr, pick);
		bt(index + 1, curr | (1 << index), pick + 1);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	int ret = 0;
	for (int i = 0; i < N; ++i) {
		string a;
		int str = 0;
		cin >> a;
		for (int j = 0; j < a.size(); ++j) {
			str |= 1 << (a[j] - 'a');
		}
		arr.push_back(str);
	}
	//a-z
	if (K < 5) cout << 0;
	else {
		int start = 0;
		start |= 1 << ('A' - 'A');
		start |= 1 << ('N' - 'A');
		start |= 1 << ('T' - 'A');
		start |= 1 << ('C' - 'A');
		start |= 1 << ('I' - 'A');
		bt(0, start, 5);
		cout << ans;
	}
	return 0;
}
