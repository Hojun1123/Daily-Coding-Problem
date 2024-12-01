#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int arr[100001];
int uf[100001];
int Find(int n) {
	if (n == uf[n]) return n;
	int ret = Find(uf[n]);
	uf[n] = ret;
	return ret;
}
void Union(int a, int b) {
	int r1 = Find(a);
	int r2 = Find(b);
	if (r1 == r2) return;
	if (r1 < r2) uf[r2] = r1;
	else uf[r1] = r2;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		uf[i] = i;
	}
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		Union(a, b);
	}
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	int cnt = 0;
	int prev = arr[0];
	for (int i = 1; i < N; ++i) {
		if (Find(prev) != Find(arr[i])) {
			cnt++;
		}
		prev = arr[i];
	}
	cout << cnt;
	return 0;
}