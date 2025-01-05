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
	int arr[5] = { 0, 0, 0, 0, 0 };
	cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];
	int ans = 0;
	while (1) {
		int ret[3] = {0, 0 ,0};
		if (arr[0]) {
			arr[0]--;
			ret[0] = 1;
		}
		if (arr[2]) {
			arr[2]--;
			ret[1] = 1;
		}
		if (arr[4]) {
			arr[4] --;
			ret[2] = 1;
		}

		//cout << ret[0] << ", " << ret[1] << ", " << ret[2] << "\n";

		if (ret[0] == 0) {
			if (arr[1]) {
				arr[1]--;
				ret[0] = 1;
			}
		}

		if (ret[2] == 0) {
			if (arr[3]) {
				arr[3]--;
				ret[2] = 1;
			}
		}

		if (ret[1] == 0) {
			if (arr[1] || arr[3]) {
				if (arr[1] > arr[3]) {
					arr[1] --;
					ret[1] = 1;
				}
				else {
					arr[3] --;
					ret[1] = 1;
				}
			}
		}

		if ((ret[0] && ret[1] && ret[2]) == 0) break;
		ans++;
	}
	cout << ans;
	return 0;
}