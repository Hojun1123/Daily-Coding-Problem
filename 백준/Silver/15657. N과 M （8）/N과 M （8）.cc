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
int input[8];
int check[8];
void recursion(int depth, int prev)
{
	if (depth == M)
	{
		for (int i = 0; i < M; ++i)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = prev; i < N; ++i)
	{
		arr[depth] = input[i];
		recursion(depth + 1, i);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> input[i];
	sort(input,input + N);
	recursion(0, 0);
	return 0;
}