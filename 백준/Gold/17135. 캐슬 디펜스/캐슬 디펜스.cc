#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int N, M, D;
int board[16][15];
int archerCheck[15];
vector<int> archer;
int answer = 0;
int dy[3] = { 0, -1, 0 };
int dx[3] = { -1, 0, 1 };
struct yx {
    int y, x;
};
int check[16][15];
void attack(int& cnt)
{
    vector<yx> result;
    for (int i = 0; i < archer.size(); ++i)
    {
        queue<yx> q;
        memset(check, 0, sizeof(int) * 15 * 15);
        q.push({ N , archer[i] });
        check[N][archer[i]] = 1;
        int nowDistance = 0;
        int outFlag = false;
        while (!q.empty())
        {
            int qSize = q.size();
            for (int j = 0; j < qSize; ++j)
            {
                yx now = q.front();
                q.pop();
                if (board[now.y][now.x])
                {
                    outFlag = true;
                    result.push_back({ now.y, now.x });
                    break;
                }
                for (int k = 0; k < 3; ++k)
                {
                    int y = now.y + dy[k];
                    int x = now.x + dx[k];
                    if (y < 0 || x < 0 || y > N || x >= M || check[y][x]) continue;
                    q.push({ y, x });
                    check[y][x] = 1;
                }
            }
            if (outFlag) break;
            if (nowDistance == D) break;
            nowDistance++;
        }
    }

    for (yx i : result)
    {
        if (board[i.y][i.x])
        {
            cnt++;
            board[i.y][i.x] = 0;
        }
    }
}
void move()
{
    for (int i = N - 1; i >= 1; --i)
    {
        for (int j = 0; j < M; ++j)
        {
            board[i][j] = board[i - 1][j];
        }
    }
    for (int j = 0; j < M; ++j)
    {
        board[0][j] = 0;
    }
}
void simulation()
{
    int cnt = 0;
    int tmp[16][15];
    memcpy(tmp, board, sizeof(board));
    for (int t = 0; t < N; ++t)
    {
        attack(cnt);
        move();
    }
    memcpy(board, tmp, sizeof(board));
    answer = max(answer, cnt);
}
void bt(int pick, int index)
{
    if (pick == 3)
    {
        simulation();
        return;
    }
    for (int i = index + 1; i < M; ++i)
    {
        if (archerCheck[i]) continue;
        archerCheck[i] = 1;
        archer.push_back(i);
        bt(pick + 1, i);
        archerCheck[i] = 0;
        archer.pop_back();
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> D;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> board[i][j];
        }
    }
    bt(0, -1);
    cout << answer;
    return 0;
}