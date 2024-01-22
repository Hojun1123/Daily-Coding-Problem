#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <vector>
using namespace std;
int N;
int dp[100001];
int arr[100001];
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	//i는 수열의 길이, j는 시작점.
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
		dp[i] = arr[i];
	}
	int s = dp[0];
	int maxValue = dp[0];
	for (int i = 1; i < N; ++i)
	{
		dp[i] = max(dp[i - 1] + arr[i], dp[i]);
		if (maxValue < dp[i])
		{
			maxValue = dp[i];
		}
		//cout << dp[i] << " ";
	}
	cout << maxValue;
	return 0;
}
