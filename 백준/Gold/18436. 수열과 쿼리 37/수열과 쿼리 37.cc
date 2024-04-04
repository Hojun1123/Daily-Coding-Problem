#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
using namespace std;
int N, M;
int arr[100000];
vector<int> tree;
int Make(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = (arr[start] & 1 ? 0 : 1);
        return tree[node];
    }
    int mid = (start + end) / 2;
    int l = Make(node * 2, start, mid);
    int r = Make(node * 2 + 1, mid + 1, end);
    tree[node] = l + r;
    return tree[node];
}
void Update(int node, int start, int end, int index, int diff)
{
    if (index < start || index > end) return;
    if (start != end)
    {
        tree[node] += diff;
        int mid = (start + end) / 2;
        Update(node * 2, start, mid, index, diff);
        Update(node * 2 + 1, mid + 1, end, index, diff);
    }
    else
    {
        tree[node] = (diff == 1 ? 1 : 0);
    }
}
int Query(int node, int start, int end, int left, int right)
{
    if (start > right || end < left) return 0;
    else if (start >= left && end <= right) return tree[node];
    int mid = (start + end) / 2;
    int l = Query(node * 2, start, mid, left, right);
    int r = Query(node * 2 + 1, mid + 1, end, left, right);
    return l + r;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    int h = ceil(log2(N)) + 1;
    tree.resize(1 << h);
    for (int i = 0; i < N; ++i) cin >> arr[i];
    cin >> M;
    Make(1, 0, N - 1);
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            int r = (arr[b - 1] & 1) + (c & 1);
            if (r == 0 || r == 2) continue;
            arr[b - 1] = c;
            if (c & 1) Update(1, 0, N - 1, b - 1, -1);
            else Update(1, 0, N - 1, b - 1, 1);
        }
        else if (a == 2) {
            //짝
            cout << Query(1, 0, N - 1, b - 1, c - 1) << "\n";
        }
        else {
            //홀
            cout << c - b + 1 - Query(1, 0, N - 1, b - 1, c - 1) << "\n";
        }
    }
    return 0;
}