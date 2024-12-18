#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;
int N, M;
vector<int> tree[500001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N - 1; ++i) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	double ll = 0;
	for (int i = 2; i <= N; ++i) {
		if (tree[i].size() == 1) ll++;
	}

	cout.precision(9);
	cout << fixed;
	cout << (double)M / ll;
	return 0;
}
