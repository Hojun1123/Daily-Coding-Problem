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
int N, M, S, E;
int graph[3001][3001];
//고속도로는 n-1과 일반도로
//몇개의 지역으로 나눌 수 있는데, 가능하면 많은 지역
//각각의 지역은 모두 같은 수의 도시를 가지고, 모든 도시는 하나의 지역에 속해야 함
//a->b의 경로가 있으면 b->a는 없어야함
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	int a, b;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		graph[a][b] = 1;
	}
	for (int i = 1; i < N; ++i) {
		graph[i][i + 1] = 1;
	}

	// N ~ 1개 도시
	for (int cnt = N; cnt >= 1; --cnt) {
		if (N % cnt) continue;
		//
		int div = N / cnt;
		int flag = 1;
		for (int i = N; i >= 1; i -= div) {
			for (int j = i; j > i - div; --j) {
				for (int k = 1; k <= i - div; ++k) {
					if (graph[j][k]) {
						//cout << i << " " << j << "\n";
						flag = 0;
						break;
					}
				}
				if (!flag) break;
			}
			if (!flag) break;
		}
		if (flag) {
			cout << cnt;
			return 0;
		}
	}
	return 0;
}
