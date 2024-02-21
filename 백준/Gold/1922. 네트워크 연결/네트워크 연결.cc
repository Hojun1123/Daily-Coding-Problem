#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int N, M;
struct Node {
    int a, b, cost;
    bool operator<(Node o) const {
        return cost < o.cost;
    }
};
int arr[1001];
vector<Node> v;
void init()
{
    for (int i = 1; i <= N; ++i)
    {
        arr[i] = i;
    }
}
int Find(int c)
{
    if (c == arr[c]) return c;
    int ret = Find(arr[c]);
    arr[c] = ret;
    return ret;
}
void Union(int a, int b)
{
    int r1 = Find(a);
    int r2 = Find(b);
    if (r1 == r2) return;
    arr[r2] = r1;
}
int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == b) continue;
        v.push_back({ a, b, c });
    }
    init();
    sort(v.begin(), v.end());
    int sc = 0;
    int r = 0;
    for (auto i : v)
    {
        int a = i.a;
        int b = i.b;
        if (Find(a) == Find(b)) continue;
        Union(a, b);
        r += i.cost;
        sc++;
        if (sc == N - 1)
            break;
    }
    cout << r;
    return 0;
}