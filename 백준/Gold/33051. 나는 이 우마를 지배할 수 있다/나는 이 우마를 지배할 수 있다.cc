#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;
int N, M, K;
//우마점수
//기본점수와 우마점수의 합
//4명이 N판
struct ret {
	int n;
	int score;
	bool operator<(ret o) const {
		if (score > o.score) return true;
		else if (score < o.score) return false;
		return n < o.n;
	}
};
ret score[4];
//플레이어 K를 M등
struct Node {
	//1 ~ 4
	int cnt[4];
	int score;
};
Node player[5];
int check(int d1, int d2, int d3, int d4) {
	score[0].n = 1;
	score[0].score = player[1].score + player[1].cnt[0] * d1 + player[1].cnt[1] * d2
		+ player[1].cnt[2] * d3 + player[1].cnt[3] * d4;
	
	score[1].n = 2;
	score[1].score = player[2].score + player[2].cnt[0] * d1 + player[2].cnt[1] * d2
		+ player[2].cnt[2] * d3 + player[2].cnt[3] * d4;

	score[2].n = 3;
	score[2].score = player[3].score + player[3].cnt[0] * d1 + player[3].cnt[1] * d2
		+ player[3].cnt[2] * d3 + player[3].cnt[3] * d4;

	score[3].n = 4;
	score[3].score = player[4].score + player[4].cnt[0] * d1 + player[4].cnt[1] * d2
		+ player[4].cnt[2] * d3 + player[4].cnt[3] * d4;

	
	//cout << d1 << " " << d2 << " " << d3 << " " << d4 << "\n";
	//for (int i = 0; i < 4; ++i) {
	//	cout << score[i].score << ", ";
	//}cout << "\n";

	sort(score, score + 4);

	return score[M - 1].n == K;
} 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K >> M;
	int a[4], s;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 4; ++j) {
			cin >> a[j];
			player[a[j]].cnt[j] ++;
		}
		for (int j = 0; j < 4; ++j) {
			cin >> s;
			player[a[j]].score += s;
		}	
	}

	for (int d4 = -100; d4 <= 0; ++d4) {
		for (int d3 = d4; d3 <= 34; ++d3) {
			for (int d2 = d3; d2 <= 100; ++d2) {
				for (int d1 = d2; d1 <= 100; ++d1) {
					if (d1 + d2 + d3 + d4 != 0) continue;
					if (check(d1, d2, d3, d4)) {
						cout << d1 << " " << d2 << " " << d3 << " " << d4;
						return 0;
					}
				}
			}
		}
	}
	cout << -1;
	return 0;
}