#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;
int N, M, A, D;
//1 n일이 남음
//i일에는 si점의 가산점을 얻을 수 있음
int arr[11111];
int dp[1011][11111];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int ans = 2100000000;
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
		dp[0][i] = dp[0][i - 1] + arr[i];
	}
	cin >> A >> D;
	for (int i = 0; i <= (N / D) + 1; ++i) {
		for (int j = D; j < N + D; ++j) {
			if(i > 0)
				dp[i][j] = max(dp[i][j - 1] + arr[j], dp[i - 1][j - D] + A);
			if (dp[i][j] >= M)
				ans = min(ans, i);
		}
	}
	cout << (ans == 2100000000 ? -1 : ans);
	return 0;
}