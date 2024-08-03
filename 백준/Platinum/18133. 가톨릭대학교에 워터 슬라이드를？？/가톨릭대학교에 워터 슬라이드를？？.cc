#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <set>
using namespace std;
int N, M;
vector<int> graph[100001];
vector<int> rev[100001];
bool visited[100001];
bool check[100001];
stack<int> s;
vector<int> ret[100001];
int gp[100001];
void dfs(int curr)
{
    for (int i = 0; i < graph[curr].size(); ++i)
    {
        int nxt = graph[curr][i];
        if (visited[nxt]) continue;
        visited[nxt] = true;
        dfs(nxt);
    }
    s.push(curr);
}
void dfs2(int curr, int cnt)
{
    for (int i = 0; i < rev[curr].size(); ++i)
    {
        int nxt = rev[curr][i];
        if (visited[nxt]) continue;
        visited[nxt] = true;
        dfs2(nxt, cnt);
    }
    ret[cnt].push_back(curr);
}
int Find(int n)
{
    if (n == gp[n]) return n;
    int rr = Find(gp[n]);
    gp[n] = rr;
    return rr;
}
void Union(int a, int b)
{
    int r1 = Find(a);
    int r2 = Find(b);
    if (r1 == r2) return;
    if (r1 < r2)
        gp[r2] = r1;
    else
        gp[r1] = r2;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        rev[b].push_back(a);
    }

    for (int i = 1; i <= N; ++i)
    {
        if (visited[i])continue;
        visited[i] = true;
        dfs(i);
    }

    int cnt = 0;
    memset(visited, 0, sizeof(visited));
    while (!s.empty())
    {
        int curr = s.top();
        s.pop();
        if (visited[curr]) continue;
        visited[curr] = true;
        dfs2(curr, cnt);
        cnt++;
    }

    /*
    for (int i = 0; i < cnt; ++i)
    {
        for (int j : ret[i])
            cout << j << " ";
        cout << "\n";
    }
    */

    for (int i = 1; i <= N; ++i) gp[i] = i;
    for (int i = 0; i < cnt; ++i)
    {
        // 그룹으로 묶기
        for (int j = 1; j < ret[i].size(); ++j) {
            Union(ret[i][0], ret[i][j]);
        }
    }
    for (int i = 1; i <= N; ++i)
    {
        // 그룹끼리 연결.
        int a = Find(i);
        for (int j = 0; j < graph[i].size(); ++j)
        {
            int b = Find(graph[i][j]);
            if (a != b) check[b] = true;
        }
    }

    int ans = 0;
    memset(visited, 0, sizeof(visited));
    for (int i = 1; i <= N; ++i)
    {
        int start = Find(i);
        if (visited[start]) continue;
        if (check[start]) continue;
        
        queue<int> q;
        q.push(start);
        visited[start] = true;
        while (!q.empty())
        {
            int now = q.front();
            q.pop();
            for (int k = 0; k < graph[now].size(); ++k)
            {
                int nxt = graph[now][k];
                if (visited[nxt]) continue;
                visited[nxt] = true;
                q.push(nxt);
            }
        }
        
        ans++;
    }
    cout << ans;
    return 0;
}