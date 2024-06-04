#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_map>
using namespace std;
int T, N;
int arr[200000];
vector<int> tree;
unordered_map<int, int> m;
int Make(int node, int start, int end)
{
    if (start == end) {
        tree[node] = arr[start];
        return tree[node];
    }
    int mid = (start + end) / 2;
    int l = Make(node * 2, start, mid);
    int r = Make(node * 2 + 1, mid + 1, end);
    tree[node] = max(l, r);
    return tree[node];
}
int Query(int node, int start, int end, int left, int right)
{
    if (left > end || right < start) return 0;
    if (start >= left && end <= right) return tree[node];
    int mid = (start + end) / 2;
    int l = Query(node * 2, start, mid, left, right);
    int r = Query(node * 2 + 1, mid + 1, end, left, right);
    return max(l, r);
}
void solve()
{
    m.clear();
    tree.clear();
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        m[arr[i]] = i;
    }
    int h = ceil(log2(N)) + 1;
    tree.resize(1 << h);
    Make(1, 0, N - 1);

    int ans = 0;
    for (int i = 0; i < N - 1; ++i)
    {
        if (i == m[arr[i]]) continue;
        if (Query(1, 0, N - 1, i + 1, m[arr[i]] - 1) > arr[i]) {
            ans = 1;
            break;
        }
    }
    cout << (ans ? "No\n" : "Yes\n");
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    for(int i = 0; i < T; ++i)
        solve();
    return 0;
 }