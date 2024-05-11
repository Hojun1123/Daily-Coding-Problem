#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <cmath>
#include <unordered_map>
#include <cstring>
#include <algorithm>
using namespace std;
int N;
int cost[501];
int result[501];    //각 건물을 짓는데 필요한 시간
int in[501];
vector<int> graph[501];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> cost[i];
        int a;
        while (true) {
            cin >> a;
            if (a == -1)break;
            graph[a].push_back(i);
            in[i]++;
        }
    }
    
    queue<int> q;
    for (int i = 1; i <= N; ++i)
    {
        if (in[i] > 0) continue;
        in[i]--;
        q.push(i);
        result[i] = cost[i];
    }
    while (!q.empty())
    {
        int qSize = q.size();
        for (int i = 0; i < qSize; ++i)
        {
            int now = q.front();
            //cout << now << " ";
            q.pop();
            for (int k = 0; k < graph[now].size(); ++k)
            {
                int nxt = graph[now][k];
                in[nxt]--;
                result[nxt] = max(result[nxt], result[now]);
                if (in[nxt] == 0) {
                    q.push(nxt);
                    result[nxt] += cost[nxt];
                }
            }
        }
    }
    for (int i = 1; i <= N; ++i) cout << result[i] << "\n";
    return 0;
}