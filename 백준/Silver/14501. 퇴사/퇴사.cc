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
int arr[16][2];
int answer[16][16];
void recursion(int l, int t, int p)
{
	if (t > N + 1)
		return;
	if (answer[l][t] < p)
		answer[l][t] = p;
	for (int i = t; i <= N; ++i)
	{
		recursion(l + 1, i + arr[i][0], p + arr[i][1]);
	}
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	int a, b;
	//시간, 금액
	//arr[y][x] y 개를 선택했을 때, x 날짜의 p
	for (int i = 1; i <= N; ++i)
	{
		cin >> a >> b;
		arr[i][0] = a;	//시간
		arr[i][1] = b;	//금액
	}
	recursion(0, 1, 0);
	int maxValue = 0;
	for (int i = 0; i <= N; ++i)
	{
		for (int j = 0; j <= N + 1; ++j)
		{
			if (maxValue < answer[i][j])
				maxValue = answer[i][j];
		}
	}
	cout << maxValue;
	return 0;
}
