#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <string>
#include <unordered_map>
#include <bitset>
#include <stack>
#include <unordered_set>
#include <set>
using namespace std;
int N, M, S, E;
struct Node {
    int n, c;
    bool operator<(Node other) const {
        return c < other.c;
    }
};
vector<Node> graph[10001];
int answer[10001];
vector<int> path[10001];
priority_queue<Node> pq;
struct Line {
    int a, b;
    bool operator<(Line o) const {
        if (a < o.a) return false;
        else if (a > o.a) return true;
        if (b < o.b) return false;
        else if (b > o.b) return true;
        return false;

    }
};
map<Line, int> lineSet;
void DFS()
{
    stack<int> s;
    s.push(E);
    while (!s.empty())
    {
        int now = s.top();
        s.pop();
        for (int i = 0; i < path[now].size(); ++i)
        {
            int next = path[now][i];
            if (lineSet[{ now, next }] == 0)
            {
                lineSet[{now, next}] = 1;
                s.push(next);
            }
        }
    }
    cout << lineSet.size();
}
void solve()
{
    //for (int i = 1; i <= N; ++i) answer[i] = 0;
    pq.push({ S, 0 });
    answer[S] = 0;
    while (!pq.empty())
    {
        Node now = pq.top();
        pq.pop();
        for (int i = 0; i < graph[now.n].size(); ++i)
        {
            Node next = graph[now.n][i];
            int nextCost = next.c + answer[now.n];
            if (answer[next.n] > nextCost) continue;
            else if (answer[next.n] == nextCost)
            {
                path[next.n].push_back(now.n);
            }
            else
            {
                path[next.n].clear();
                path[next.n].push_back(now.n);
                answer[next.n] = nextCost;
                pq.push({ next.n, nextCost });
            }
        }
    }

    cout << answer[E] << "\n";

    DFS();
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ b, c });
    }
    cin >> S >> E;
    solve();
    return 0;
}