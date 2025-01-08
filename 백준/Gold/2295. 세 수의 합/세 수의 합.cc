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
unordered_set<int> s;
//x y z / x + y + z
int arr[1000];
struct Node {
	int a, b;
	int s;
	bool operator<(const Node& o) const {
		return s < o.s;
	}
};
vector<Node> vec;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	int a;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
		s.insert(arr[i]);
	}
	//a, b, c, d
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			vec.push_back({i, j, arr[i] + arr[j] });
		}
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < N - 1; ++i) {
		for(int j = i + 1; j < N; ++j){
			int left = 0;
			int right = vec.size() - 1;
			while (left < right) {
				int mid = (left + right) / 2;
				int r = vec[mid].s + arr[i];
				if (r == arr[j]) {
					ans = max(ans, arr[j]);
					break;
				}
				else if (r > arr[j]) {
					right = mid;
				}
				else {
					left = mid + 1;
				}
			}
		}
	}
	cout << ans;
	return 0;
}