#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
long long arr[100001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> arr[i];
	sort(arr, arr + N);
	int cnt = 0;
	long long ans = 0;
	for (int i = N - 1; i >= 0; --i) {
		if (cnt == 0 || cnt == 1) ans += arr[i];
		else cnt = -1;
		cnt++;
	}
	cout << ans;
	return 0;
}