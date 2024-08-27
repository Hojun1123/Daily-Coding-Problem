#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <stack>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;
int N, M;
int cost[501][501];///회차, 무기
int dp[505][505];//x회차에 y무기를 사용할 경우 최소값.
int main()
{
    // 노드가 전부 연결, 차수가 홀수인 노드가 0 or 2 개
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> cost[i][j];
            dp[i][j] = 1987654321;
        }
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < M; ++j) {
            int minValue = 987654321;
            for (int k = 0; k < M; ++k) {
                if (k == j) continue;
                int curr = dp[i - 1][k] + cost[i][j];
                dp[i][j] = min(dp[i][j], curr);
            }
        }
    }

    int mv = 987654321;
    for (int i = 0; i < M; ++i) {
        mv = min(mv, dp[N][i]);
    }
    cout << mv;
    return 0;
}