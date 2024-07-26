#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <string>
using namespace std;
int N, M;
int check[2000];
vector<int> graph[2000];
int flag = 0;
void dfs(int n, int depth)
{
    if (depth == 4)
    {
        flag = 1;
        return;
    }
    for (int i = 0; i < graph[n].size(); ++i)
    {
        int nxt = graph[n][i];
        if (check[nxt]) continue;
        check[nxt] = 1;
        dfs(nxt, depth + 1);
        check[nxt] = 0;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 0; i < N; ++i)
    {
        check[i] = 1;
        dfs(i, 0);
        check[i] = 0;
    }
    cout << flag;
    return 0;
}