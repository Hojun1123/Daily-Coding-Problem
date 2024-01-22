#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <vector>
using namespace std;
int A, K;
int arr[2000001];
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> A >> K;
	for (int i = A; i <= K; ++i)
	{
		arr[i] = 987654321;
	}
	arr[A] = 0;
	for (int i = A; i <= K; ++i)
	{
		if(arr[i] + 1 < arr[i + 1])
			arr[i + 1] = arr[i] + 1;
		if(arr[i] + 1 < arr[i * 2])
			arr[i * 2] = arr[i] + 1;
	}
	cout << arr[K];
	return 0;
}
