#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <list>
using namespace std;
int arr[100001];
int dp[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= 100000; ++i)
	{
		dp[i] = dp[i - 1] + arr[i];
	}

	int a, b;
	for (int i = 0; i < M; ++i)
	{
		cin >> a >> b;
		cout << dp[b] - dp[a - 1] << "\n";
	}

	return 0;
}
