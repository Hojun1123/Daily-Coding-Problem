#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
int N, M, T;
struct Node{
    int a, b, cost;
    bool operator<(Node o) const {
        return cost < o.cost;
    }
};
vector<Node> graph;
int arr[10001];
int Find(int n)
{
    if (n == arr[n]) return n;
    int ret = Find(arr[n]);
    arr[n] = ret;
    return ret;
}
void init()
{
    for (int i = 1; i <= N; ++i)
        arr[i] = i;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> T;
    int a, b, c;
    for (int i = 0; i < M; ++i)
    {
        cin >> a >> b >> c;
        if (a < b)
            graph.push_back({ a, b, c });
        else
            graph.push_back({ b, a, c });
    }
    sort(graph.begin(), graph.end());
    init();
    int sc = 0;
    int answer = 0;
    int ss = 0;
    for (int i = 0; i < M; ++i)
    {
        int q = graph[i].a;
        int p = graph[i].b;
        int r1 = Find(q);
        int r2 = Find(p);
        if (Find(q) == Find(p))continue;
        if (r1 < r2) arr[r2] = r1;
        else arr[r1] = r2;
        answer += graph[i].cost;
        sc++;
        if (sc == N - 1) break;
        ss += T;
        answer += ss;
    }
    cout << answer;
    return 0;
}