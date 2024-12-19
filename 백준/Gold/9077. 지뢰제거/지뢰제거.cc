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
int T, N;
int arr[10022][10022];
void solve() {
	memset(arr, 0, sizeof(arr));
	cin >> N;
	int a, b;
	for (int i = 0; i < N; ++i) {
		cin >> a >> b;
		a += 5; b += 5;
		for (int y = -5; y <= 5; ++y) {
			for (int x = -5; x <= 5; ++x) {
				arr[a + x][b + y] += 1;
			}
		}
	}
	int v = 0;
	for (int i = 5; i <= 10005; ++i) {
		for (int j = 5; j <= 10005; ++j) {
			v = max(v, arr[i][j]);
		}
	}
	cout << v << "\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	for (int i = 0; i < T; ++i)solve();
	return 0;
}
