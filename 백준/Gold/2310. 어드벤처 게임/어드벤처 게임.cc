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
int N;
struct Room {
    char a;
    int cost;
};
struct Node {
    int m, n;
};
Room arr[1001];
int check[555][1001];
void solve()
{
    memset(check, 0, sizeof(check));
    vector<int> graph[1001];
    for(int i = 1; i <= N; ++i)
    {
        cin >> arr[i].a >> arr[i].cost;
        int nn;
        while (true)
        {
            cin >> nn;
            if (nn == 0) break;
            graph[i].push_back(nn);
        }
    }
    queue<Node> q;
    q.push({0, 1});
    check[0][1] = 1;
    while (!q.empty())
    {
        Node now = q.front();
        q.pop();
        if (now.n == N) {
            cout << "Yes\n";
            return;
        }
        for (int i = 0; i < graph[now.n].size(); ++i)
        {
            int nxt = graph[now.n][i];
            int nxtCost;
            if (arr[nxt].a == 'E')
            {
                nxtCost = now.m;
            }
            else if (arr[nxt].a == 'L')
            {
                nxtCost = max(arr[nxt].cost, now.m);
            }
            else
            {
                nxtCost = now.m - arr[nxt].cost;
            }
            if (nxtCost < 0) continue;
            if (check[nxtCost][nxt])continue;
            check[nxtCost][nxt] = 1;
            q.push({ nxtCost, nxt });
        }
    }
    cout << "No\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (true)
    {
        cin >> N;
        if (N == 0) break;
        solve();
    }
    return 0;
}