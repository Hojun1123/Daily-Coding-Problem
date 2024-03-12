#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
int N, M, K;
long long arr[1000001];
vector<long long> tree;
long long makeSegmentTree(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = arr[start];
        return arr[start];
    }

    int mid = (start + end) / 2;
    long long leftResult = makeSegmentTree(node * 2, start, mid);
    long long rightResult = makeSegmentTree(node * 2 + 1, mid + 1, end);
    tree[node] = leftResult + rightResult;
    return tree[node];
}
long long Sum(int node, int left, int right, int start, int end)
{
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    long long leftResult = Sum(node * 2, left, right, start, mid);
    long long rightResult = Sum(node * 2 + 1, left, right, mid + 1, end);
    return leftResult + rightResult;
}
void UpdateSegmentTree(int node, int start, int end, int index, long long diff)
{
    if (index < start || index > end) return;
    tree[node] = tree[node] + diff;
    if (start != end)
    {
        int mid = (start + end) / 2;
        UpdateSegmentTree(node * 2, start, mid, index, diff);
        UpdateSegmentTree(node * 2 + 1, mid + 1, end, index, diff);
    }
}
 int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }
    int height = ceil(log2(N));
    int s = 1 << (height + 1);
    tree.resize(s);
    makeSegmentTree(1, 0, N - 1);

    for (int i = 0; i < M + K; ++i)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            long long diff = c - arr[b - 1];
            arr[b - 1] = c;
            UpdateSegmentTree(1, 0, N - 1, b-1, diff);
        }
        else
        {
            cout << Sum(1, b-1, c-1, 0, N - 1) << "\n";
        }
    }
}