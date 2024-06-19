#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
int N, M;
struct Node {
    int n, cost;
};
vector<Node> tree[1001];
int check[1001];
int goal;
int endFlag = 0;
void dfs(int n, int s)
{
    if (endFlag) return;
    if (goal == n) {
        cout << s << "\n";
        endFlag = 1;
        return;
    }
    for (int i = 0; i < tree[n].size(); ++i)
    {
        int nxt = tree[n][i].n;
        if (check[nxt]) continue;
        check[nxt] = 1;
        int c = tree[n][i].cost;
        dfs(nxt, s + c);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    int a, b, c;
    for (int i = 0; i < N - 1; ++i)
    {
        cin >> a >> b >> c;
        tree[a].push_back({ b, c });
        tree[b].push_back({a, c});
    }
    for (int i = 0; i < M; ++i)
    {
        endFlag = 0;
        memset(check, 0, sizeof(check));
        cin >> a >> goal;
        check[a] = 1;
        dfs(a, 0);
    }
    return 0;
}