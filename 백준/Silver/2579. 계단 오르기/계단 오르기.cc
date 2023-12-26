#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <list>


using namespace std;
int N;
// N 은 1 ~300
// 각 점수는 10000 이하
int score[300];
int dp[300];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// + 1 or + 2
	// 
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> score[i];
	}

	if (N == 1)
		cout << score[0];
	else if (N == 2)
		cout << score[0] + score[1];
	else
	{
		dp[0] = score[0];
		dp[1] = score[1] + score[0];	//01
		dp[2] = max(dp[0] + score[2], score[1] + score[2]);

		for (int i = 3; i < N; ++i)
		{
			dp[i] = max(dp[i - 3] + score[i - 1] + score[i], dp[i - 2] + score[i]);
		}
		cout << dp[N - 1];
	}
	
	return 0;
}
