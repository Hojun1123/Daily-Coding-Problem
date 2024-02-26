#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>
#include <deque>
#include <deque>
#include <map>
#include <vector>
#include <sstream>
using namespace std;
int R, C;
int arr[1500][1500];    //
struct yx {
    int y, x;
};
yx backjo[2];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int check[1500][1500];
int FillNum = 0;
void FloodFill()
{
    queue<yx> q;
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            if (check[i][j] == 0 && arr[i][j])
            {
                FillNum++;
                q.push({ i, j });
                check[i][j] = FillNum;
                while (!q.empty())
                {
                    yx now = q.front();
                    q.pop();
                    for (int k = 0; k < 4; ++k)
                    {
                        int y = now.y + dy[k];
                        int x = now.x + dx[k];
                        if (x >= 0 && y >= 0 && x < C && y < R && check[y][x]==0 && arr[y][x])
                        {
                            q.push({ y, x });
                            check[y][x] = FillNum;
                        }
                    }
                }
            }
        }
    }
}
int answer[1200000];
int tmp[1500][1500];
void init()
{
    for (int i = 1; i <= FillNum; ++i)
    {
        answer[i] = i;
    }
}
int Find(int curr)
{
    if (curr == answer[curr]) return curr;
    int ret = Find(answer[curr]);
    answer[curr] = ret;
    return ret;
}
void Union(int a, int b)
{
    int r1 = Find(a);
    int r2 = Find(b);
    if (r1 == r2) return;
    answer[r2] = r1;
}
int MeltIce()
{
    queue<yx> q;
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            if (check[i][j] > 0)
            {
                q.push({ i, j });
            }
        }
    }
    //unionFind
    init();

    int count = 0;
    while (!q.empty())
    {
        int qSize = q.size();
        memset(tmp, 0, sizeof(int) * 1500 * 1500);
        for (int i = 0; i < qSize; ++i)
        {
            yx now = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k)
            {
                int y = now.y + dy[k];
                int x = now.x + dx[k];
                if (x < 0 || y < 0 || y >= R || x >= C || tmp[y][x]) continue;
                if (check[y][x] == 0)
                {
                    tmp[y][x] = check[now.y][now.x];  //다음 영역을 현재의 영역번호로 색칠
                    q.push({ y, x });
                }
                else
                {
                    //다른 영역을 만났음 > Union
                    Union(check[now.y][now.x], check[y][x]);
                    if (Find(check[backjo[0].y][backjo[0].x]) == Find(check[backjo[1].y][backjo[1].x]))
                    {
                        return count;
                    }
                }
            }
        }
        for (int i = 0; i < R; ++i)
        {
            for (int j = 0; j < C; ++j)
            {
                if(tmp[i][j]> 0)
                check[i][j] = tmp[i][j];
            }
        }
        count++;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> R >> C;
    int bIndex = 0;
    for (int i = 0; i < R; ++i)
    {
        string a;
        cin >> a;
        for (int j = 0; j < C; ++j)
        {
            if(a[j] == '.')
            {
                arr[i][j] = 1;
            }
            else if(a[j] == 'L')
            {
                arr[i][j] = 1;
                backjo[bIndex].y = i;
                backjo[bIndex].x = j;
                bIndex++;
            }
            else
            {
                arr[i][j] = 0;
            }
        }
    }
    FloodFill();
    cout << MeltIce();
    return 0;
}