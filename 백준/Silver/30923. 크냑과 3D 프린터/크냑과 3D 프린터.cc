#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <cstring>
#include <cmath>
using namespace std;
int N;
int arr[33333];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N; for (int i = 0; i < N; ++i) cin >> arr[i];
	int prev = 0;
	long long result = N + N + arr[N - 1];
	for (int i = 0; i < N; ++i) { 
		result = result + abs(prev - arr[i]) + arr[i] * 2;
		prev = arr[i];
	}
	cout << result;
	return 0;
}