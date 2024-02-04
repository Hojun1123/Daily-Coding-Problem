#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <vector>
#include<cstring>
using namespace std;
struct cell {
    int y;
    int x;
    int h;
    bool operator<(cell other) const {
        if (h < other.h) return false;
        else if (h > other.h) return true;
        return false;
    }
};
int answer = 0;
int check[300][300];
int arr[300][300];
int M, N;
int dy[4] = { 1, -1 , 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
priority_queue<cell> pq;
void dfs(int yy, int xx, int hh)
{
    for (int k = 0; k < 4; ++k)
    {
        int y = dy[k] + yy;
        int x = dx[k] + xx;
        int h = arr[y][x];
        if (x >= 0 && y >=0 && x < M && y < N && check[y][x] == 0)
        {
            check[y][x] = 1;
            if (hh < h)
            {
                //다음 칸에 물을 채울 수 없는 경우, 새로운 시작점 +
                pq.push({ y, x, h });
            }
            else
            {
                //다음 칸에 물을 채울 수 있는 경우
                answer += hh - h;
                //시작지점의 높이를 기준으로 탐색
                dfs(y, x, hh);
            }
        }
    }
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> M >> N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> arr[i][j];
            if (i == 0 || j == 0 || i == N - 1 || j == M - 1)
            {
                pq.push({ i, j, arr[i][j] });
                check[i][j] = 1;
            }
        }
    }

    while (!pq.empty())
    {
        cell now = pq.top();
        pq.pop();
        dfs(now.y, now.x, now.h);
    }
    cout << answer;
    return 0;
}