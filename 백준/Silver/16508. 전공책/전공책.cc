#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;
string T;
int N;
string arr[16];
int price[16];
int check[26];
int need[26];
int ans = 987654321;
void bt(long long curr, int index, int p) {
	int ret = 0;
	for (int i = 0; i < 26; ++i) {
		if (need[i] > check[i]) {
			ret = 1;
		}
	}
	if (ret == 0) {
		ans = min(ans, p);
		return;
	}
	if (index == N) return;
	bt(curr, index + 1, p);
	for (int i = 0; i < arr[index].size(); ++i) {
		check[arr[index][i] - 'A']++;
	}
	bt(curr | (1 << index), index + 1, price[index] + p);
	for (int i = 0; i < arr[index].size(); ++i) {
		check[arr[index][i] - 'A']--;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> price[i] >> arr[i];
	}
	for (int i = 0; i < T.size(); ++i) {
		need[T[i] - 'A']++;
	}
	bt(0, 0, 0);
	cout << (ans > 900000000 ? -1 : ans);
	return 0;
}