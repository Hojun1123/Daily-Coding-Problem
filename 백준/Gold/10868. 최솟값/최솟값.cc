#include <vector>
#include <cmath>
#include <iostream>
#include <stack>
#include <queue>
#include <cstring>
#include <map>
#include <unordered_map>
using namespace std;
int N, M;
int arr[100001];
vector<int> tree;
int Make(int node, int start, int end)
{
    if (start == end) 
    {
        tree[node] = arr[start];
        return tree[node];
    }
    int mid = (start + end) / 2;
    tree[node] = min(Make(node * 2, start, mid), Make(node * 2 + 1, mid + 1, end));
    return tree[node];
}
int Get(int node, int start, int end, int left, int right)
{
    if (start > right || end < left) return 2000000000;
    if (start >= left && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return min(Get(node * 2, start, mid, left, right), Get(node * 2 + 1, mid + 1, end, left, right));
}
void solve()
{
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }
    int h = ceil(log2(N)) + 1;
    tree.resize(1 << h);
    Make(1, 0, N - 1);
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        cout << Get(1, 0, N - 1, min(a, b) - 1, max(a, b) - 1) << "\n";
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