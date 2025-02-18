#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;
int K, N;
long long arr[10011];
int check(long long n) {
	long long cnt = 0;
	for (int i = 0; i < K; ++i) {
		cnt += arr[i] / n;
		if (cnt >= N) return 1;
	}
	return cnt >= N;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> K >> N;
	for (int i = 0; i < K; ++i) {
		cin >> arr[i];
	}
	//1 `1000000
	long long left = 1;
	long long right = 2222222222;
	long long ans = 0;
	while (left < right) {
		long long mid = (left + right) / 2;
		if (check(mid)) {
			ans = mid;
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}
	cout << ans;
	return 0;
}