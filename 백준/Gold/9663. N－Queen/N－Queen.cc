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
int board[15];
int answer = 0;

bool check(int index)
{
	for (int i = 0; i < index; ++i)
	{
		if (board[index] == board[i] || index - i == (board[i] > board[index] ? board[i] - board[index] : board[index] - board[i]))
		{
			return false;
		}
	}
	return true;
}

void dfs(int index)
{
	if (index >= N)
	{
		answer++;
		return;
	}
	for (int i = 0; i < N; ++i)
	{
		board[index] = i;
		if (check(index))
		{
			dfs(index + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	dfs(0);
	cout << answer;
	return 0;
}