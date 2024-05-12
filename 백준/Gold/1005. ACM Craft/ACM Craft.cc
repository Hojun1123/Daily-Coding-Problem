#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int T, N, K, W;
int cost[1001];
int in[1001];
vector<int> graph[1001];
int result[1001];
void solve()
{
    memset(in, 0, sizeof(in));
    memset(result, 0, sizeof(result));
    cin >> N >> K;
    for (int i = 1; i <= N; ++i) {
        cin >> cost[i];
        graph[i].clear();
    }
    int a, b;
    for (int i = 0; i < K; ++i)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        in[b]++;
    }
    cin >> W;
    
    queue<int> q;
    for (int i = 1; i <= N; ++i)
    {
        if (in[i] == 0) {
            if (i == W) {
                cout << cost[i] << "\n";
                return;
            }
            q.push(i);
            result[i] = cost[i];
        }
    }
    while (!q.empty())
    {
        int qSize = q.size();
        for (int s = 0; s < qSize; ++s)
        {
            int now = q.front();
            q.pop();
            for (int i = 0; i < graph[now].size(); ++i)
            {
                int next = graph[now][i];
                in[next]--;
                result[next] = max(result[next], result[now]);
                if (in[next] == 0)
                {
                    q.push(next);
                    result[next] += cost[next];
                    if (next == W)
                    {
                        cout << result[W] << "\n";
                        return;
                    }
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        solve();
    }
    return 0;
}