#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
int N,A,B,DA,DB;
int check[500][500];
int da[4] = { 1, 1, -1, -1 };
int db[4] = { 1, -1, 1, -1 };
struct Node {
	int a, b;
};
queue<Node> q;
// 순서대로 두사람 지목
// 두 사람이 각각 한 명씩 지목

// 지목권 A, B
// 자신의 왼OR오로 정확히 DA만큼 떨어진 사람을 지목
// 만약 지목권 B가 있었으면 게임 끝
//
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> A >> B >> DA >> DB;
	A--; B--;
	int cnt = 0;
	check[A][B] = 1;
	q.push({ A, B });
	while (!q.empty()) {
		int qSize = q.size();
		int r = 3;
		for (int i = 0; i < qSize; ++i) {
			Node curr = q.front();
			q.pop();
			for (int k = 0; k < 4; ++k) {
				int nxtA = (N + curr.a + DA * da[k]) % N;
				if (nxtA == curr.b) {
					r = min(1, r);
				}
				int nxtB = (N + curr.b + DB * db[k]) % N;
				if (nxtB == nxtA) {
					r = min(2, r);
				}
				if (check[nxtA][nxtB]) continue;
				check[nxtA][nxtB] = 1;
				q.push({ nxtA, nxtB });
			}
		}
		if (r < 3) {
			cout << cnt + r;
			return 0;
		}
		cnt += 2;
	}
	cout << "Evil Galazy";
	return 0;
}