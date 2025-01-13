#include <vector>
#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <unordered_map>
#include <map>
#include <cmath>
#include <deque>
#include <unordered_set>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//3명으로 구성
	//코딩 실력이 좋으면 팀워크 떨어짐, 또는 그 반대
	//세명의 합이 0
	int N;
	cin >> N;
	int arr[10000];
	for (int i = 0; i < N; ++i) cin >> arr[i];
	sort(arr, arr + N);
	long long ans = 0;
	for (int i = 0; i < N - 2; ++i) {
		for (int j = i + 1; j < N - 1; ++j) {
			int curr = arr[i] + arr[j];
			int *ll = lower_bound(&arr[j + 1], &arr[N], -curr);
			int *uu = upper_bound(&arr[j + 1], &arr[N], -curr);
			//cout << *uu << " , " << *ll << "\n";
			ans += (uu - ll);
		}
	}
	cout << ans;
	//-20000 ~ 20000
	return 0;
}