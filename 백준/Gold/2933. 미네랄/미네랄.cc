#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <cstring>
using namespace std;
int N, M;
string arr[101];
int K;
int input[100];
int check[100][100];
struct yx {
    int y, x;
};
queue<yx> q;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int currNum = 0;
int p1(int index)
{
    int deleteFlag = 0;
    int currHeight = N - input[index];
    if (index % 2 == 0)
    {
        //->
        for (int i = 0; i < M; ++i)
        {
            if (arr[currHeight][i] == 'x')
            {
                arr[currHeight][i] = '.';
                deleteFlag = 1;
                break;
            }
        }
    }
    else
    {
        for (int i = M - 1; i >= 0; --i)
        {
            if (arr[currHeight][i] == 'x')
            {
                arr[currHeight][i] = '.';
                deleteFlag = 1;
                break;
            }
        }
    }
    return deleteFlag;
}
void p2()
{
    //위치 수정이 필요 없는 미네랄 덩어리
    memset(check, 0, sizeof(check));
    for (int i = 0; i < M; ++i)
    {
        q.push({ N, i });
    }

    while (!q.empty())
    {
        int qSize = q.size();
        for (int i = 0; i < qSize; ++i)
        {
            yx now = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k)
            {
                int y = dy[k] + now.y;
                int x = dx[k] + now.x;
                if (x < 0 || y < 0 || x >= M || y >= N) continue;
                if (arr[y][x] != 'x') continue;
                if (check[y][x]) continue;
                check[y][x] = 1;
                q.push({ y, x });
            }
        }
    }
}
vector<yx> area[3];
int visited[100][100];
void ff()
{
    while (!q.empty())
    {
        yx now = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int y = dy[i] + now.y;
            int x = dx[i] + now.x;
            if (x < 0 || y < 0 || x >= M || y >= N) continue;
            if (arr[y][x] != 'x') continue;
            if (visited[y][x]) continue;
            visited[y][x] = 1;
            q.push({ y, x });
            area[currNum - 1].push_back({ y, x });
        }
    }
}
void p3()
{
    memset(visited, 0, sizeof(visited));
    currNum = 1;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (arr[i][j] == '.')continue;
            if (check[i][j] || visited[i][j]) continue;
            q.push({ i, j });
            visited[i][j] = 1;
            area[currNum - 1].push_back({ i,j });
            ff();
            currNum++;
        }
    }
}
void p4()
{
    for (int i = 0; i < currNum - 1; ++i)
    {
        int minDistance = 123;
        for (int j = 0; j < area[i].size(); ++j)
        {
            yx now = area[i][j];
            int y = now.y;
            while (true)
            {
                y += 1;
                if (visited[y][now.x] == i + 1) continue;
                if (y == N || arr[y][now.x] == 'x') {
                    minDistance = min(minDistance, y - now.y - 1);
                    break;
                }
            }
        }
        //cout << minDistance << "\n";

        for (int j = 0; j < area[i].size(); ++j)
        {
            arr[area[i][j].y][area[i][j].x] = '.';
        }
        for (int j = 0; j < area[i].size(); ++j)
        {
            arr[area[i][j].y + minDistance][area[i][j].x] = 'x';
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    cin >> K;
    for (int i = 0; i < K; ++i)
        cin >> input[i];
    //첫번째는 ->
    //바닥이 1

    for (int i = 0; i < K; ++i)
    {
        if (p1(i))
        {
            p2();
            p3();
            p4();
        }
        area[0].clear();
        area[1].clear();

        /*cout << "\n";
        for (int j = 0; j < N; ++j)
        {
            cout << arr[j] << "\n";
        }*/
    }
    for (int i = 0; i < N; ++i) cout << arr[i] << "\n";
    return 0;
 }