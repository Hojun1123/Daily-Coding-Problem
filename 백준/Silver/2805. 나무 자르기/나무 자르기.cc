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
int N, M;
int arr[1000000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	cin >> M;
	long long left, right, mid;
	left = 0;
	right = 0;
	int a;
	for (int i = 0; i < N; ++i)
	{
		cin >> a;
		if (a > right)
			right = a;
		arr[i] = a;
	}

	long long s;
	while (left <= right)
	{
		mid = (left + right) / 2;
		s = 0;
		for (int i = 0; i < N; ++i)
		{
			if (arr[i] >= mid)
				s += arr[i] - mid;
		}

		if (s >= M)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	cout << right;
	return 0;
}