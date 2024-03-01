#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <deque>
#include <unordered_map>
#include <cstring>
using namespace std;
int W, H;
string arr[500];
int sy, sx, ey, ex;
struct yx {
    int y, x;
    int cost;
    bool operator<(yx o) const {
        return cost > o.cost;
    }
};
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int answer[500][500];
vector<yx> graph[500][500];
void dijkstra()
{
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            answer[i][j] = 3333333;
        }
    }
    priority_queue<yx> pq;
    answer[sy][sx] = 0;
    pq.push({ sy, sx, 0 });
    while (!pq.empty())
    {
        yx now = pq.top();
        pq.pop();
        for (int i = 0; i < 4; ++i)
        {
            int y = now.y;
            int x = now.x;
            int currDirCost = answer[y][x];
            while (true)
            {
                y += dy[i];
                x += dx[i];
                if (x < 0 || y < 0 || x >= W || y >= H)
                {
                    //1. 미로 바깥으로 떨어지는 경우
                    break;
                }
                if (arr[y][x] >= '0' && arr[y][x] <= '9')
                {
                    //2. 미끌시간
                    currDirCost += arr[y][x] - '0';
                }
                else if (arr[y][x] == 'H')
                {
                    //3. 구멍
                    break;
                }
                else if (arr[y][x] == 'R')
                {
                    //4. 미끄러지다 바위를 만나는 경우
                    if (currDirCost < answer[y - dy[i]][x - dx[i]])
                    {
                        answer[y - dy[i]][x - dx[i]] = currDirCost;
                        pq.push({ y - dy[i], x - dx[i], currDirCost});
                    }
                    break;
                }
                else if (arr[y][x] == 'E')
                {
                    if (currDirCost < answer[y][x])
                    {
                        answer[y][x] = currDirCost;
                        pq.push({ y, x, currDirCost });
                    }
                    break;
                }
            }
        }
    }
     
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> W >> H;
    for (int i = 0; i < H; ++i)
    {
        cin >> arr[i];
        for (int j = 0; j < W; ++j)
        {
            if (arr[i][j] == 'T')
            {
                sy = i; sx = j;
                arr[i][j] = 0;
            }
            else if (arr[i][j] == 'E')
            {
                ey = i; ex = j;
            }
        }
    }
    dijkstra();
    cout << (answer[ey][ex] > 3000000 ? -1 : answer[ey][ex]);
    return 0;
}