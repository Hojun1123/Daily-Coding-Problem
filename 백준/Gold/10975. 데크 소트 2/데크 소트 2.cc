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
using namespace std;
int N;
int arr[50];
int ix[50];
int tmp[50];
deque<int> ret[50];
unordered_map<int, int> um;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) { 
		cin >> arr[i];
		tmp[i] = arr[i];
	}
	//작은 순.
	sort(tmp, tmp+ N);
	for (int i = 0; i < N; ++i) {
		//수: 인덱스
		um[tmp[i]] = i;
	}
	for (int i = 0; i < N; ++i) {
		ix[i] = um[arr[i]];
	}
	int cnt = 0;
	ret[cnt].push_back(ix[0]);
	for (int i = 1; i < N; ++i) {
		int r = 0;
		for (int j = 0; j <= cnt; ++j) {
			if (ret[j].front() - 1 == ix[i]) {
				r = 1;
				ret[j].push_front(ix[i]);
				break;
			}
			else if (ret[j].back() + 1 == ix[i]) {
				r = 1;
				ret[j].push_back(ix[i]);
				break;
			}
		}
		if (!r) {
			cnt++;
			ret[cnt].push_back(ix[i]);
		}
	}
	cout << cnt + 1;
	return 0;
}
