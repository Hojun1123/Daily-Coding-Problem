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
unordered_map<string, bool> um;
int cnt = 0;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N >> M;
	string a;
	for (int i = 0; i < N; ++i) {
		cin >> a;
		um[a] = 1;
	}
		
	for (int i = 0; i < M; ++i) {
		cin >> a;
		if (um[a]) cnt++;
	}
	cout << cnt;
	return 0;
}