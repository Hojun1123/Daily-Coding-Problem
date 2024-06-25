#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <unordered_map>
using namespace std;
int T;
int N, M, W;
struct Node {
    int n, t;
};
vector<Node> graph[501];
int check[501];
int answer[501];
int cnt[501];
void solve()
{
    cin >> N >> M >> W;
    int a, b, c;
    for (int i = 1; i <= N; ++i) graph[i].clear();

    for (int i = 0; i < M; ++i)
    {
        cin >> a >> b >> c;
        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }
    for (int i = 0; i < W; ++i)
    {
        cin >> a >> b >> c;
        graph[a].push_back({ b, -c });
    }


    for (int num = 1; num <= N; ++num)
    {
        memset(cnt, 0, sizeof(cnt));
        memset(check, 0, sizeof(check));
        for (int i = 1; i <= N; ++i) answer[i] = 1987654321;

        queue<int> q;
        q.push(num);
        answer[num] = 0;
        check[num] = 1;
        while (!q.empty())
        {
            int now = q.front();
            q.pop();
            cnt[now]++;
            check[now] = 0;
            if (cnt[now] >= N) {
                //for (int i = 1; i <= N; ++i) cout << answer[i] << " ";
                cout << "YES\n";
                return;
            }

            for (int i = 0; i < graph[now].size(); ++i)
            {
                Node nxt = graph[now][i];
                int nextCost = nxt.t + answer[now];
                if (nextCost >= answer[nxt.n]) continue;
                answer[nxt.n] = nextCost;
                if (check[nxt.n] == 0)
                {
                    check[nxt.n] = 1;
                    q.push(nxt.n);
                }
            }
        }
    }
    cout << "NO\n";
    return;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    for (int i = 0; i < T; ++i)
        solve();
    return 0;
}