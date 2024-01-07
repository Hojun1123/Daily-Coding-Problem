#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <list>
#include <cmath>
using namespace std;
int N;
int answer = 1000000;
int weight[1000][3];
int dp[1000][3];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> weight[i][0] >> weight[i][1] >> weight[i][2];
	}

	dp[0][0] = weight[0][0];
	dp[0][1] = weight[0][1];
	dp[0][2] = weight[0][2];

	for (int i = 1; i < N; ++i)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + weight[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + weight[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + weight[i][2];
	}
	cout << min(dp[N - 1][0], min(dp[N - 1][1], dp[N - 1][2]));
	return 0;
}