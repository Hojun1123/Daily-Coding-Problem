#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <vector>
using namespace std;
int T, N, M;
struct Node {
    int a, b, cost;
    bool operator<(Node o) const {
        return cost < o.cost;
    }
};
vector<Node> v;
int arr[21];
int Fd(int n)
{
    if (n == arr[n])return n;
    int ret = Fd(arr[n]);
    arr[n] = ret;
    return ret;
}
void Un(int a, int b)
{
    int r1 = Fd(a); int r2 = Fd(b);
    if (r1 == r2) return;
    arr[r2] = r1;
}
int solve()
{
    cin >> N >> M;
    v.clear();
    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({ a, b, c });
    }
    for (int i = 1; i <= N; ++i)
    {
        arr[i] = i;
    }
    sort(v.begin(), v.end());
    int result = 0;
    int sc = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        int a = v[i].a;
        int b = v[i].b;
        if (Fd(a) == Fd(b)) continue;
        Un(a, b);
        sc++;
        result += v[i].cost;
        if (sc == N - 1)break;
    }
    return result;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        cout << "Case #" << i + 1 << ": " << solve() << " meters\n";
    }

    return 0;
}