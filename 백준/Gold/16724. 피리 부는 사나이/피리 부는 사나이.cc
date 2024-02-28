#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <deque>
#include <unordered_map>
#include <cstring>
using namespace std;
int N, M;
string str[1000];
int check[1000][1000];
int fillNum = 0;
int unionCount = 0;
int arr[1000001];
void init()
{
    for (int i = 1; i <= N * M; ++i)
    {
        arr[i] = i;
    }
}
int Find(int c)
{
    if (c == arr[c]) return c;
    int ret = Find(arr[c]);
    arr[c] = ret;
    return ret;
}
void Union(int a, int b)
{
    int r1 = Find(a);
    int r2 = Find(b);
    if (r1 == r2) return;
    arr[r2] = r1;
    unionCount++;
}
void dfs(int sy, int sx)
{
    if (str[sy][sx] == 'U')
    {
        if (check[sy - 1][sx] == 0)
        {
            check[sy - 1][sx] = fillNum;
            dfs(sy - 1, sx);
        }
        else if (check[sy - 1][sx] != fillNum)
        {
            Union(check[sy - 1][sx], fillNum);
        }
    }
    else if (str[sy][sx] == 'D')
    {
        if (check[sy + 1][sx] == 0)
        {
            check[sy + 1][sx] = fillNum;
            dfs(sy + 1, sx);
        }
        else if (check[sy + 1][sx] != fillNum)
        {
            Union(check[sy + 1][sx], fillNum);
        }
    }
    else if (str[sy][sx] == 'R')
    {
        if (check[sy][sx + 1] == 0)
        {
            check[sy][sx + 1] = fillNum;
            dfs(sy, sx + 1);
        }
        else if (check[sy][sx + 1] != fillNum)
        {
            Union(check[sy][sx + 1], fillNum);
        }
    }
    else if (str[sy][sx] == 'L')
    {
        if (check[sy][sx - 1] == 0)
        {
            check[sy][sx - 1] = fillNum;
            dfs(sy, sx - 1);
        }
        else if (check[sy][sx - 1] != fillNum)
        {
            Union(check[sy][sx - 1], fillNum);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        cin >> str[i];
    }
    init();
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (check[i][j] == 0)
            {
                fillNum++;
                check[i][j] = fillNum;
                dfs(i, j);
            }
        }
    } 
    cout << fillNum - unionCount;
    return 0;
}