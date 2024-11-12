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
int arr[200][200];
int check[200][200][31];
struct yx {
    int y, x, k;
};
queue<yx> q;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int dy2[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dx2[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };
int K, M, N;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //원숭이는 K번만 위와 같이 움직임
    //그외에는 그냥 인접한 칸
    //머나먼 여행을 떠나는데, 맨왼위에서 맨오아래
    cin >> K >> M >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> arr[i][j];
        }
    }
    q.push({ 0, 0, 0 });
    check[0][0][0] = 1;
    int cnt = 0;
    while (!q.empty()) {
        int qSize = q.size();
        for (int k = 0; k < qSize; ++k) {
            yx curr = q.front();
            q.pop();
            if (curr.y == N - 1 && curr.x == M - 1) {
                cout << cnt;
                return 0;
            }
            if (curr.k < K) {
                for (int i = 0; i < 8; ++i) {
                    int y = dy2[i] + curr.y;
                    int x = dx2[i] + curr.x;
                    if (x < 0 || y < 0 || x >= M || y >= N) continue;
                    if (arr[y][x] || check[y][x][curr.k + 1]) continue;
                    check[y][x][curr.k + 1] = 1;
                    q.push({ y, x, curr.k + 1 });
                }
            }
            
            for (int i = 0; i < 4; ++i) {
                int y = dy[i] + curr.y;
                int x = dx[i] + curr.x;
                if (x < 0 || y < 0 || x >= M || y >= N) continue;
                if (arr[y][x] || check[y][x][curr.k]) continue;
                check[y][x][curr.k] = 1;
                q.push({ y, x, curr.k});
            }
        }
        cnt++;
    }
    cout << -1;
    return 0;
}