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
int arr[7];
void recursion(int depth)
{
	if (depth == M)
	{
		for (int i = 0; i < M; ++i)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; ++i)
	{
		arr[depth] = i;
		recursion(depth + 1);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	recursion(0);
	return 0;
}