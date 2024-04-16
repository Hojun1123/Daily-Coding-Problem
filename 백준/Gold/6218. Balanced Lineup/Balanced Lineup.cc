#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <cmath>
#include <unordered_map>
using namespace std;
int N, Q;
vector<int> minTree;
vector<int> maxTree;
int arr[200000];
int minMake(int node, int start, int end)
{
    if (start == end)
    {
        minTree[node] = arr[start];
        return minTree[node];
    }
    int mid = (start + end) / 2;
    int l = minMake(node * 2, start, mid);
    int r = minMake(node * 2 + 1, mid + 1, end);
    minTree[node] = min(l, r);
    return minTree[node];
}
int maxMake(int node, int start, int end)
{
    if (start == end)
    {
        maxTree[node] = arr[start];
        return maxTree[node];
    }
    int mid = (start + end) / 2;
    int l = maxMake(node * 2, start, mid);
    int r = maxMake(node * 2 + 1, mid + 1, end);
    maxTree[node] = max(l, r);
    return maxTree[node];
}
int getMinValue(int node, int start, int end, int left, int right)
{
    if (right < start || left > end) return 987654321;
    if (left <= start && right >= end) return minTree[node];
    int mid = (start + end) / 2;
    int l = getMinValue(node * 2, start, mid, left, right);
    int r = getMinValue(node * 2 + 1, mid + 1, end, left, right);
    return min(l, r);
}
int getMaxValue(int node, int start, int end, int left, int right)
{
    if (right < start || left > end) return 0;
    if (left <= start && right >= end) return maxTree[node];
    int mid = (start + end) / 2;
    int l = getMaxValue(node * 2, start, mid, left, right);
    int r = getMaxValue(node * 2 + 1, mid + 1, end, left, right);
    return max(l, r);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> Q;
    for (int i = 0; i < N; ++i) cin >> arr[i];
    int height = ceil(log2(N)) + 1;
    minTree.resize(1 << height);
    maxTree.resize(1 << height);
    minMake(1, 0, N - 1);
    maxMake(1, 0, N - 1);
    for (int i = 0; i < Q; ++i)
    {
        int a, b;
        cin >> a >> b;
        cout << getMaxValue(1, 0, N - 1, a - 1, b - 1) - getMinValue(1, 0, N - 1, a - 1, b - 1) << "\n";
    }
    return 0;
}
