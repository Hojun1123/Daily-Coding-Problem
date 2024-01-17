#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
using namespace std;
int N, M;
int check[9];
int arr[8];
void recursion(int length)
{
	if (length == M)
	{
		for (int i = 0; i < M; ++i)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	for (int i = 1; i <= N; ++i)
	{
		if (!check[i])
		{
			check[i] = 1;
			arr[length] = i;
			recursion(length + 1);
			check[i] = 0;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	recursion(0);
	return 0;
}