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
int A, B, N;
int arr[1001];
vector<int> v;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> A >> B >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	//증가 or 감소.
	v.push_back(abs(A - B));
	for (int i = 0; i < N; ++i) {
		v.push_back(abs(arr[i] - B) + 1);
	}
	sort(v.begin(), v.end());
	cout << v[0];
	return 0;
}