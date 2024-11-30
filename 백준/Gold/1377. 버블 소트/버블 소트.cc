#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
int N;
struct Node {
	int index, v;
	bool operator<(Node o) const {
		if (v == o.v) return index < o.index;
		return v < o.v;
	}
};
vector<Node> arr;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 0; i < N; ++i){
		int a;
		cin >> a;
		arr.push_back({ i, a });
	}
	sort(arr.begin(), arr.end());

	int ans = -1;
	for (int i = 0; i < N; ++i) {
		ans = max(ans, arr[i].index - i);
		//cout << arr[i].index - i << " ";
	}
	cout << ans + 1;
	return 0;
}