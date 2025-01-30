#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
int N;
int arr[100000];
long long check(int n) {
	long long sum = 0;
	for (int i = 1; i < N; ++i) {
		sum += abs((long long)n * i - arr[i]);
	}
	return sum;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	long long left = 0;
	long long right = 1000000000;
	while (right - left >= 3) {
		long long lm = (left * 2 + right) / 3;
		long long rm = (right * 2 + left) / 3;
		if (check(lm) < check(rm)) {
			right = rm;
		}
		else {
			left = lm;
		}
	}
	long long ans = 100000000000000;
	for (int i = 0; i < 3; ++i) {
		ans = min(ans, check(left + i));
	}
	cout << ans;
	return 0;
}