#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <map>
using namespace std;
int M, N;
int arr[8];
int input[10001];
int check[10001];
void recursion(int depth)
{
	if (depth == M)
	{
		for (int i = 0; i < M; ++i)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= 10000; ++i)
	{
		if (check[i] >= input[i])
			continue;
		check[i] ++;
		arr[depth] = i;
		recursion(depth + 1);
		check[i] --;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	int a;
	for (int i = 0; i < N; ++i)
	{
		cin >> a;
		input[a] ++;
	}
	recursion(0);
	return 0;
}