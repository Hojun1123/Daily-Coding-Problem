#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;
int N, M, K;
int cost[1001];
int arr[1001];
int bal[1001];
struct Node {
    int a, b, c;
    bool operator<(Node o) const {
        return c < o.c;
    }
};
vector<Node> graph;
void init()
{
    for (int i = 1; i <= N; ++i)
    {
        arr[i] = i;
    }
}
int Find(int n)
{
    if (n == arr[n]) return n;
    int ret = Find(arr[n]);
    arr[n] = ret;
    return ret;
}
int Union(int a, int b)
{
    int r1 = Find(a);
    int r2 = Find(b);
    if (r1 == r2) return 0;
    if (bal[r1] && bal[r2]) return 0;
    else if (bal[r1]) {
        arr[r2] = r1;
    }
    else{
        arr[r1] = r2;
    }
    return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin >> N >> M >> K;
    int a, b, c;
    for (int i = 0; i < K; ++i)
    {
        cin >> a;
        bal[a] = 1;
    }
    for (int i = 0; i < M; ++i)
    {
        cin >> a >> b >> c;
        graph.push_back({ a, b, c });
    }
    init();
    sort(graph.begin(), graph.end());
    int ans = 0;
    for (int i = 0; i < M; ++i)
    {
        int d = graph[i].a;
        int e = graph[i].b;
        int r = Union(d, e);
        if (r) {
            ans += graph[i].c;
        }
    }
    cout << ans;
    return 0;
}