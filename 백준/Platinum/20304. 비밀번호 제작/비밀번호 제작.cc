#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;
//0~N
//안전거리는 2진법으로 표현한 두 비밀번호의 서로 다른 자리의 개수
int N, M;
int pwd[100000];
//2^20 = 1,000,000
int visited[1000001];
queue<int>  q;
int main() {
	ios::sync_with_stdio(0);	cin.tie(0);cout.tie(0);
	cin >> N >> M; for (int i = 0; i < M; ++i) cin >> pwd[i];
	for (int i = 0; i < M; ++i) {
		q.push(pwd[i]);
		visited[pwd[i]] = 1;
	}

	int cnt = 0;
	while (!q.empty())
	{
		int qSize = q.size();
		for (int i = 0; i < qSize; ++i) {
			int curr = q.front();
			//cout << curr << " ";
			q.pop();
			for (int k = 0; k <= 20; ++k) {
				int p = (1 << k);
				if (p & curr) {
					int nxt = curr - p;
					if (nxt < 0) continue;
					if (visited[nxt]) continue;
					visited[nxt] = 1;
					q.push(nxt);
				}
				else {
					int nxt = curr + p;
					if (nxt > N) continue;
					if (visited[nxt]) continue;
					visited[nxt] = 1;
					q.push(nxt);
				}
			}
		}
		//cout << "\n";
		cnt++;
	}

	cout << cnt - 1;
}