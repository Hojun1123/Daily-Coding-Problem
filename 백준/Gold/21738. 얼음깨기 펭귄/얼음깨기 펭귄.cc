#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#include <unordered_map>
#include <regex>
using namespace std;
int N, S, P;
//328000
struct Node {
    int n, c;
    bool operator < (Node o) const {
        return c > o.c;
    }
};
priority_queue<Node> pq;
int ans[328001];
vector<Node> graph[328001];
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> S >> P;
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back({ b, 1 });
        graph[b].push_back({ a, 1 });
    }
    for (int i = 1; i <= N; ++i) ans[i] = 98765432;
    
    pq.push({ P, 0 });
    ans[P] = 0;
    while (!pq.empty())
    {
        Node now = pq.top();
        pq.pop();
        if (now.c > ans[now.n]) continue;
        for (int i = 0; i < graph[now.n].size(); ++i)
        {
            Node nxt = graph[now.n][i];
            int nxtCost = nxt.c + ans[now.n];
            if (nxtCost >= ans[nxt.n]) continue;
            ans[nxt.n] = nxtCost;
            pq.push({ nxt.n, nxtCost });
        }
    }

    vector<int> ret;
    for (int i = 1; i <= S; ++i) {
        ret.push_back(ans[i]);
    }
    sort(ret.begin(), ret.end());
    cout << (N - ret[0] - ret[1] - 1);
    return 0;
}