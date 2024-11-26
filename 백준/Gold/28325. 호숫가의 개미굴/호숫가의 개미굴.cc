#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;
int N;
long long ans = 0;
long long arr[250001];
int check[250001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
		if (arr[i]) {
			check[i] = 1;
			ans += arr[i];
		}
	}
	if (ans == 0) {
		cout << N / 2;
		return 0;
	}
	
	int start = 0;
	for (int i = 0; i < N; ++i) {
		if (check[i]) {
			start = i;
			break;
		}
	}

	int cnt = 0;
	int idx = start;
	while(true){
		if (check[idx]) {
			ans += (cnt + 1) / 2;
			cnt = 0;
		}
		else {
			cnt++;
		}
		idx++;
		if (idx == N) idx = 0;
		if (idx == start) break;
	}
	if (cnt > 0) {
		ans += (cnt + 1) / 2;
	}
	cout << ans;
	return 0;
}