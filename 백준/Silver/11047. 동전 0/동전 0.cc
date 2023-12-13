#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
using namespace std;
int N, K;
stack<int> coins;

int main() {
	cin >> N;
	cin >> K;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt = 0;
	int coin;
	for (int i = 0; i < N; ++i)
	{
		cin >> coin;
		coins.push(coin);
	}

	int c;
	while (K)
	{
		c = coins.top();
		coins.pop();
		if (K >= c)
		{
			cnt += K / c;
			K %= c;
		}
	}
	cout << cnt;
	return 0;
}
