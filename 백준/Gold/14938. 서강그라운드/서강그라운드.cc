#include <iostream>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
int N, M, R;
//무방향 그래프
int graph[101][101];
int items[101];
int check[101];

void dfs(int index, int w)
{
    int next;
    for (int i = 1; i <= N; ++i)
    {
        
        next = graph[index][i];
        if (next > 0 && next && check[i] > next + w && next + w <= M)
        {
            check[i] = w + next;
            dfs(i, w + next);
        }
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> R;
    for (int i = 1; i <= N; ++i)
    {
        cin >> items[i];
    }

    int a, b, c;
    for (int i = 0; i < R; ++i)
    {
        cin >> a >> b >> c;
        if (graph[a][b] == 0)
        {
            graph[a][b] = c;
            graph[b][a] = c;
        }
        else
        {
            if (graph[a][b] > c)
            {
                graph[a][b] = c;
                graph[b][a] = c;
            }
        }
    }

    int temp;
    int answer = 0;
    for (int i = 1; i <= N; ++i)
    {
        temp = 0;
        for (int j = 1; j <= N; ++j)
            check[j] = 10000;

        check[i] = -1;
        dfs(i, 0);
        for (int j = 1; j <= N; ++j)
        {
            if (check[j] <= M)
            {
                temp += items[j];
            }
        }

        //cout << temp << " ";
        if (temp > answer)
            answer = temp;
    }
    cout << answer;
}