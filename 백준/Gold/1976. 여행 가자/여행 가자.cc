#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <string>
#include <unordered_map>
#include <bitset>
#include <stack>
#include <unordered_set>
#include <cstring>
#include <sstream>
using namespace std;
int N, M;
int graph[200][200];
int arr[200];
int plan[1000];
void init() {
	for (int i = 0; i < N; ++i) arr[i] = i;
}
int Find(int a) {
	if (a == arr[a]) return a;
	int ret = Find(arr[a]);
	arr[a] = ret;
	return ret;
}
void Union(int a, int b) {
	int r1 = Find(a);
	int r2 = Find(b);
	if (r1 == r2) return;
	arr[r2] = r1;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> graph[i][j];
		}
	}
	init();
	for (int i = 0; i < N; ++i) {
		for (int j = i; j < N; ++j) {
			if (graph[i][j]) {
				Union(i, j);
			}
		}
	}
	for (int i = 0; i < M; ++i) {
		cin >> plan[i];
	}
	bool result = true;
	int prev = Find(plan[0] - 1);
	for (int i = 0; i < M; ++i) {
		int curr = Find(plan[i] - 1);
		if (prev != curr) {
			result = false;
			break;
		}
	}
	cout << (result ? "YES" : "NO");
	return 0;
}