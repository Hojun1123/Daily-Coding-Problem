#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
// 크기가 무한인 모눈
// 양의 정수 모양으로 채울거임
//숫자 1을 0,0에 씀
struct yx{
	int v, s, y, x;
};
vector<yx> arr;
int ret[55][55];
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//r1행부터 r2행까지
	//모든 행은 같은 길이
	// 공백의 길이는 최소
	// 모든 숫자의 길이
	int r1, c1, r2, c2;
	int maxNum = 1;
	cin >> r1 >> c1 >> r2 >> c2;


	for (int i = r1; i <= r2; ++i) {
		for (int j = c1; j <= c2; ++j) {
			if (i == 0 && j == 0) {
				ret[i - r1][j - c1] = 1;
				continue;
			}
			int p = max(abs(i), abs(j));
			int size = (1 +  2*p) * (1 + 2*p);
			
			int sy = p;
			int sx = p;
			int dir = 0;
			int endflag = 0;
			for(int k = 0; k < 4; ++k){
				for (int l = 0; l < 2 * p; ++l) {
					if (sy == i && sx == j) {
						ret[i - r1][j - c1] = size;
						maxNum = max(maxNum, size);
						endflag = 1;
						break;
					}
					size--;
					sy += dy[k];
					sx += dx[k];
				}
				if (endflag) break;
			}
		}
	}

	int len = 0;
	while (maxNum > 0) {
		maxNum /= 10;
		len++;
	}

	for (int i = 0; i <= r2 - r1; ++i) {
		for (int j = 0; j <= c2 - c1; ++j) {
			int tmp = 0;
			int tmpn = ret[i][j];
			while (ret[i][j] > 0) {
				ret[i][j] /= 10;
				tmp++;
			}
			for (int k = 0; k < len - tmp; ++k) cout << " ";
			cout << tmpn << " ";
		}
		cout << "\n";
	}
	return 0;
}