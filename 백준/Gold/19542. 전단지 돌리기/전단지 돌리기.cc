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
//1 ~ n
int N, S, D;
vector<int> graph[100001];
int depth;
int check[100001];
int result[100001];
int ans = 0;
int dfs(int n)
{
    int r = 0;
    for (int i = 0; i < graph[n].size(); ++i)
    {
        if (check[graph[n][i]]) continue;
        check[graph[n][i]] = 1;
        r = max(r, dfs(graph[n][i]));
    }
    result[n] = r;
    if (r >= D && n != S) {
        ans++;
    }
    return r + 1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> S >> D;
    depth = D;
    for (int i = 0; i < N - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    check[S] = 1;
    dfs(S);
    cout << (ans * 2);
    return 0;
}