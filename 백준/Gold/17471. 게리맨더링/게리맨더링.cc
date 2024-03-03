#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <deque>
#include <unordered_map>
#include <cstring>
using namespace std;
int N;
vector<int> graph[11];
int people[11];
int groupA[11];
int visited[11];
int answer = 99999999;
bool bfs(int flag)
{
    memset(visited, 0, 44);
    queue<int> q;
    for (int i = 1; i <= N; ++i)
    {
        if (groupA[i] == flag)
        {
            q.push(i);
            visited[i] = 1;
            break;
        }
    }
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int i : graph[now])
        {
            if (visited[i] == 0 && groupA[i] == flag)
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
    for (int i = 1; i <= N; ++i)
    {
        if (groupA[i] != flag || (groupA[i] == flag && visited[i])) continue;
        return false;
    }
    return true;
}
void calDiff()
{
    int a = 0;
    int b = 0;
    for (int i = 1; i <= N; ++i)
    {
        if (groupA[i]) a += people[i];
        else b += people[i];
    }
    answer = min(answer, abs(a - b));
}
void divideArea(int depth, int pCnt)
{
    if (pCnt == N) return;
    if (depth > N)
    {
        if (bfs(1) && bfs(0))
        {
            calDiff();
        }
        return;
    }

    divideArea(depth + 1, pCnt);
    groupA[depth] = 1;
    divideArea(depth + 1, pCnt + 1);
    groupA[depth] = 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> people[i];
    for (int i = 1; i <= N; ++i)
    {
        int a, b;
        cin >> a;
        for(int j = 0; j < a; ++j) 
        {
            cin >> b;
            graph[i].push_back(b);
        }
    }
    divideArea(1, 0);
    cout << (answer > 9999988 ? -1 : answer);
    return 0;
}