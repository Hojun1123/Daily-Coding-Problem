#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#include <unordered_map>
#include <regex>
using namespace std;
//어두워지기전에 호텔로 내려와야함
//산의 지도가 입력M
//A-Z a-z
// 인접한 정수 중 높이 차이가 T보다 크지 않는 곳만 이동 가능
// 높이가 낮거나 같은곳은 1초
// 높은곳으로가려면 차이의 제곱만큼 걸림
// D보다 크지 않은 시간동안 올라갈 수 있는 최대 높이
int N, M, T, D;
int arr[25][25];
struct yx {
    int y, x;
};
struct Node {
    int y, x, c;
    bool operator<(Node o) const {
        return c > o.c;
    }
};
int result[25][25][25][25];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
void dijkstra(int sy, int sx) {
    priority_queue<Node> pq;
    pq.push({ sy, sx });
    //sy, sx에서 시작할때.
    result[sy][sx][sy][sx] = 0;
    while (!pq.empty())
    {
        Node now = pq.top();
        pq.pop();
        if (now.c > result[sy][sx][now.y][now.x]) continue;
        for (int i = 0; i < 4; ++i) {
            int y = dy[i] + now.y;
            int x = dx[i] + now.x;
            if (x < 0 || y < 0 || x >= M || y >= N) continue;
            if (abs(arr[y][x] - arr[now.y][now.x]) > T) continue;
            int nxtCost = result[sy][sx][now.y][now.x];
            if (arr[y][x] - arr[now.y][now.x] > 0) {
                nxtCost += (arr[y][x] - arr[now.y][now.x]) * (arr[y][x] - arr[now.y][now.x]);
            }
            else {
                nxtCost++;
            }
            if (nxtCost >= result[sy][sx][y][x]) continue;
            result[sy][sx][y][x] = nxtCost;
            pq.push({ y, x });
        }
    }
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> T >> D;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            char a;
            cin >> a;
            if (a < 'a') {
                arr[i][j] = a - 'A';
            }
            else {
                arr[i][j] = 26 + a - 'a';
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            for (int ii = 0; ii < N; ++ii) {
                for (int jj = 0; jj < M; ++jj) {
                    result[i][j][ii][jj] = 1987654321;
                }
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            dijkstra(i, j); 
        }
    }

    int maxValue = arr[0][0];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (result[0][0][i][j] > 1900000000) continue;
            if (result[i][j][0][0] > 1900000000) continue;
            int rr = result[0][0][i][j] + result[i][j][0][0];
            if (rr <= D && maxValue < arr[i][j]) {
                maxValue = arr[i][j];
            }
        }
    }
    cout << maxValue;
    return 0;
}