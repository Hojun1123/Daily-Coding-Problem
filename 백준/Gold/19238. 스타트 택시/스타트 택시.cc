#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <string>
#include <unordered_map>
#include <bitset>
#include <stack>
#include <unordered_set>
#include <cstring>
using namespace std;
int N, M, K;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int arr[20][20];
int check[20][20];
int SY, SX;
int DY, DX;
struct yx {
    int y, x;
    bool operator<(yx o) const {
        if (y > o.y) return true;
        else if (y < o.y) return false;
        if (x > o.x) return true;
        else if (x < o.x) return false;
        return false;
    }
};
vector<yx> des;
bool bfs()
{
    memset(check, 0, sizeof(check));
    priority_queue<yx> pq;
    check[SY][SX] = 1;
    pq.push({ SY, SX });
    queue<yx> tmp;
    int cnt = 0;
    while (!pq.empty())
    {
        int qSize = pq.size();
        for (int i = 0; i < qSize; ++i)
        {
            yx now = pq.top();
            pq.pop();
            if (arr[now.y][now.x] > 1)
            {
                SY = now.y;
                SX = now.x;
                DY = des[arr[now.y][now.x]].y;
                DX = des[arr[now.y][now.x]].x;
                K -= cnt;
                //cout << SY << " " << SX << " : " << DY << " " << DX << "\n";
                arr[now.y][now.x] = 0;
                return true;
            }
            for(int k = 0; k < 4; ++k)
            {
                int y = dy[k] + now.y;
                int x = dx[k] + now.x;
                if (x < 0 || y < 0 || x >= N || y >= N || check[y][x] || arr[y][x] == 1)continue;
                tmp.push({ y, x });
                check[y][x] = 1;
            }
        }
        while (!tmp.empty()) {
            pq.push(tmp.front());
            tmp.pop();
        }
        cnt++;
    }
    return false;
}
bool bfs2()
{
    memset(check, 0, sizeof(check));
    queue<yx> pq;
    check[SY][SX] = 1;
    pq.push({ SY, SX });
    int cnt = 0;
    while (!pq.empty())
    {
        int qSize = pq.size();
        for (int i = 0; i < qSize; ++i)
        {
            yx now = pq.front();
            pq.pop();
            if (now.y == DY && now.x == DX)
            {
                SY = now.y;
                SX = now.x;
                K -= cnt;
                if (K < 0) return false;
                K += cnt * 2;
                return true;
            }
            for (int k = 0; k < 4; ++k)
            {
                int y = dy[k] + now.y;
                int x = dx[k] + now.x;
                if (x < 0 || y < 0 || x >= N || y >= N || check[y][x] || arr[y][x] == 1)continue;
                pq.push({ y, x });
                check[y][x] = 1;
            }
        }
        cnt++;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> K;
    for(int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j) cin >> arr[i][j];
    }
    cin >> SY >> SX;
    SY--; SX--;
    des.push_back({ 0, 0 });
    des.push_back({ 0, 0 });    //2 ~
    for (int i = 2; i < M + 2; ++i) { 
        int a, b, c, d; 
        cin >> a >> b >> c >> d;
        arr[a - 1][b - 1] = i;
        des.push_back({ c - 1, d - 1 });
    }

    for (int i = 0; i < M; ++i)
    {
        if (!bfs()) {
            cout << -1;
            return 0;
        }
        if (!bfs2()) {
            cout << -1;
            return 0;
        }
    }
    cout << K;
    return 0;
}
 