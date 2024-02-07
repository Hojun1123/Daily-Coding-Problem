#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int N, M;
int arr[100][100];
int check[100][100];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int answer = 0;
struct yx {
    int y;
    int x;
    int d;
    bool operator<(yx o) const {
        if (d < o.d) return false;
        else if (d > o.d) return true;
        return false;
    }
};
priority_queue<yx> pq;

void bfs(int yy, int xx, int depth)
{
    for (int k = 0; k < 4; ++k)
    {
        int y = dy[k] + yy;
        int x = dx[k] + xx;
        if (x < 0 || y < 0 || x >= M || y >= N || check[y][x]) continue;
        check[y][x] = 1;
        if (arr[y][x] >= depth)
        {
            pq.push({ y, x, arr[y][x]});
        }
        else
        {
            //cout <<depth << ":" << y << x << "\n";
            answer += depth - arr[y][x];
            bfs(y, x, depth);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> arr[i][j];
            if (i == 0 || j == 0 || i == N - 1 || j == M - 1)
            {
                pq.push({ i, j, arr[i][j]});
                check[i][j] = 1;
            }
        }
    }

    while (!pq.empty())
    {
        yx now = pq.top();
        pq.pop();
        bfs(now.y, now.x, now.d);
    }
    cout << answer;
    return 0;
}