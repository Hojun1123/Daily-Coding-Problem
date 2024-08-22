#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;
int N, K, S, X, Y;
int arr[222][222];
int check[222][222];
int dy[4] = { 1 ,-1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
struct yx {
    int y, x;
};
queue<yx> q[1001];
void bfs(int n)
{
    int qSize = q[n].size();
    for (int i = 0; i < qSize; ++i)
    {
        yx now = q[n].front();
        q[n].pop();
        for (int j = 0; j < 4; ++j)
        {
            int y = dy[j] + now.y;
            int x = dx[j] + now.x;
            if (x < 0 || y < 0 || x >= N || y >= N) continue;
            if (arr[y][x]) continue;
            arr[y][x] = n;
            q[n].push({ y, x });
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> arr[i][j];
            q[arr[i][j]].push({ i, j });
        }
    }
    cin >> S >> X >> Y;
    
    for (int t = 0; t < S; ++t)
    {
        for (int i = 1; i <= K; ++i)
        {
            bfs(i);
        }

        //cout << "\n";
        //for (int q = 0; q < N; ++q) {
        //    for (int p = 0; p < N; ++p) cout << arr[q][p] << " "; cout << "\n";
        //}
    }
    cout << arr[X- 1][Y - 1];
    return 0;
}