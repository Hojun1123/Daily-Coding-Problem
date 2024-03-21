#include <vector>
#include <cmath>
#include <iostream>
#include <stack>
#include <queue>
#include <cstring>
#include <map>
#include <unordered_map>
using namespace std;
int N, Q;
long long arr[100000];
vector<long long> tree;
long long Make(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = arr[start];
        return tree[node];
    }
    int mid = (start + end) / 2;
    long long l = Make(node * 2, start, mid);
    long long r = Make(node * 2 + 1, mid + 1, end);
    tree[node] = l + r;
    return tree[node];
}
long long Sum(int node, int start, int end, int left, int right)
{
    if (start > right || end < left) return 0;
    if (start >= left && end <= right) return tree[node];
    int mid = (start + end) / 2;
    long long l = Sum(node * 2, start, mid, left, right);
    long long r = Sum(node * 2 + 1, mid + 1, end, left, right);
    return l + r;
}
void Update(int node, int start, int end, int index, long long diff)
{
    if (index > end || index < start) return;
    tree[node] += diff;
    if (start != end)
    {
        int mid = (start + end) / 2;
        Update(node * 2, start, mid, index, diff);
        Update(node * 2 + 1, mid + 1, end, index, diff);
    }
}
void solve()
{
    cin >> N >> Q;
    for (int i = 0; i < N; ++i) cin >> arr[i];
    int h = ceil(log2(N)) + 1;
    tree.resize(1 << h);
    Make(1, 0, N - 1);
    for (int i = 0; i < Q; ++i)
    {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        if (y < x) {
            int tmp = y;
            y = x;
            x = tmp;
        }
        cout << Sum(1, 0, N - 1, x - 1, y - 1) << "\n";
        long long diff = b - arr[a - 1];
        arr[a - 1] = b;
        Update(1, 0, N - 1, a - 1, diff);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}