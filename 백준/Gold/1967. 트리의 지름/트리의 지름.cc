#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;
int N;
struct Node {
    int n, c;
};
vector<Node> v[10001];
int ans = 0;
int dfs(int n)
{
    int prevMaxCost = 0;
    int maxCost = 0;
    int ret = 0;
    for (int i = 0; i < v[n].size(); ++i)
    {
        // (부모 -> 다음 노드) + 그 노드의 트리의 최대 길이 
        Node curr = v[n][i];
        int cost = dfs(curr.n) + curr.c;
        if (cost > maxCost) {
            prevMaxCost = maxCost;
            maxCost = cost;
        }
        else if (cost > prevMaxCost)
        {
            prevMaxCost = cost;
        }
        ret = max(ret, maxCost);
    }
    //cout << ret << " " << maxCost + prevMaxCost << " ";
    ans = max(ans, maxCost + prevMaxCost);
    return ret;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N - 1; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({ b, c });
    }

    if (N == 1) {
        cout << 0;
    }
    else {
        dfs(1);
        cout << ans;
    }
    return 0;
}