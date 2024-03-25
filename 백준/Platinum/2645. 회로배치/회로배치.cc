#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
using namespace std;
int N, M, K;
struct yx {
    int y, x;
};
struct Node {
    yx n;
    int cost;
    bool operator<(Node o) const {
        return cost > o.cost;
    }
};
int SY, SX;
int EY, EX;
int board[50][50];
int answer[50][50];
vector<yx> v[8];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
vector<yx> path[50][50];
vector<yx> result;
vector<yx> ansPath;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    cin >> SY >> SX >> EY >> EX;
    SY--; SX--; EY--; EX--;
    cin >> K >> M;  
    for (int i = 0; i < M; ++i)
    {
        int n;
        cin >> n;
        for (int j = 0; j < n; ++j)
        {
            int y, x;
            cin >> y >> x;
            v[i].push_back({y - 1, x - 1});
        }
    }
    for (int i = 0; i < M; ++i)
    {
        yx prev = v[i][0];
        for (int j = 1; j < v[i].size(); ++j)
        {
            yx now = v[i][j];
            if (prev.y == now.y)
            {
                if (prev.x < now.x)
                {
                    for (int k = prev.x; k <= now.x; ++k)
                    {
                        board[prev.y][k] = 1;
                    }
                }
                else
                {
                    for (int k = now.x; k <= prev.x; ++k)
                    {
                        board[prev.y][k] = 1;
                    }
                }
            }
            else
            {
                if (prev.y < now.y)
                {
                    for (int k = prev.y; k <= now.y; ++k)
                    {
                        board[k][prev.x] = 1;
                    }
                }
                else
                {
                    for (int k = now.y; k <= prev.y; ++k)
                    {
                        board[k][prev.x] = 1;
                    }
                }
            }
            prev = now;
        }
    }

    //debug
    /*
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    */
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            answer[i][j] = 987654321;
        }
    }
    answer[SY][SX] = 1;
    priority_queue<Node> pq;
    pq.push({ {SY, SX}, 1 });
    while (!pq.empty())
    {
        Node now = pq.top();
        pq.pop();
        for (int k = 0; k < 4; ++k)
        {
            int y = dy[k] + now.n.y;
            int x = dx[k] + now.n.x;
            if (x < 0 || y < 0 || x >= N || y >= N) continue;
            int cost = answer[now.n.y][now.n.x];
            if (board[y][x]) cost += K;
            else cost += 1;
            if (cost > answer[y][x]) continue;
            else if (cost == answer[y][x])
            {
                path[y][x].push_back({ now.n.y, now.n.x });
            }
            else
            {
                path[y][x].clear();
                path[y][x].push_back({ now.n.y, now.n.x });
                answer[y][x] = cost;
                pq.push({ { y, x }, cost });
            }
        }
    }

    stack<yx> s;
    s.push({ EY, EX });
    while (!s.empty())
    {
        yx now = s.top();
        s.pop();
        result.push_back(now);
        if (now.y == SY && now.x == SX)
            break;
        //cout << now.y << " " << now.x << "\n";
        for(int k = 0; k < path[now.y][now.x].size(); ++k)
        {
            int y = path[now.y][now.x][k].y;
            int x = path[now.y][now.x][k].x;
            if (y < 0 || x < 0 || x >= N || y >= N) continue;
            s.push({ y, x });
        }
    }
    
    cout << answer[EY][EX] << " ";

    //1은 세로|, 0은 가로-
    yx prev = result[result.size() - 1];
    ansPath.push_back(prev);    // 시작
    yx now = result[result.size() - 2];
    int prevDir = (prev.y == now.y) ? 0 : 1;
    prev = now;
    for (int i = result.size() - 3; i >= 0; --i)
    {
        yx now = result[i];
        int nowDir = (prev.y == now.y) ? 0 : 1;
        if (nowDir != prevDir)
        {
            ansPath.push_back(prev);
            prevDir = nowDir;
        }
        prev = now;
    }
    ansPath.push_back(prev);    // 종료
    cout << ansPath.size() << " ";
    for (int i = 0; i < ansPath.size(); ++i)
        cout << ansPath[i].y + 1 << " " << ansPath[i].x + 1<< " ";
    return 0;
}