#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;
int N, M, T;
int ans[1001][1001];
struct xy {
	int p, x, y;
};
vector<xy> city;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> T;
	for (int i = 0; i < N; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		city.push_back({ a, b, c });
	}


	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			ans[i][j] = 987654321;
		}
	}

	for (int i = 0; i < N - 1; ++i) {
		for (int j = i + 1; j < N; ++j) {
			int dis = abs(city[i].x - city[j].x) + abs(city[i].y - city[j].y);
			if (city[i].p && city[j].p && dis > T) {
				ans[i][j] = T;
				ans[j][i] = T;
			}
			else {
				ans[i][j] = dis;
				ans[j][i] = dis;
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++ j) {
			for (int k = 0; k < N; ++k) {
				ans[j][k] = min(ans[j][k], ans[j][i] + ans[i][k]);
			}
		}
	}

	cin >> M;
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		cout << ans[a- 1][b-1] << "\n";
	}
	return 0;
}