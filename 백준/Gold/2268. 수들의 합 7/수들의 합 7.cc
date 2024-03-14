#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <deque>
#include <unordered_map>
#include <cstring>
#include <cmath>
using namespace std;
int arr[1000000];
vector<long long> segTree;
int N, M;
long long Make(int node, int start, int end)
{
    if (start == end)
    {
        segTree[node] = arr[start];
        return segTree[node];
    }
    int mid = (start + end) / 2;
    long long leftSum = Make(node * 2, start, mid);
    long long rightSum = Make(node * 2 + 1, mid + 1, end);
    segTree[node] = leftSum + rightSum;
    return segTree[node];
}
long long Sum(int node, int start, int end, int left, int right)
{
    if (left > end || start > right) return 0;
    if (left <= start && right >= end) return segTree[node];
    int mid = (start + end) / 2;
    long long leftSum = Sum(node * 2, start, mid, left, right);
    long long rightSum = Sum(node * 2 + 1, mid + 1, end, left, right);
    return leftSum + rightSum;
}
void Update(int node, int start, int end, int index, long long diff)
{
    if (index < start || end < index) return;
    segTree[node] += diff;
    if (start != end)
    {
        int mid = (start + end) / 2;
        Update(node * 2, start, mid, index, diff);
        Update(node * 2 + 1, mid + 1, end, index, diff);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    int s = ceil(log2(N)) + 1;
    segTree.resize(1 << s);
    Make(1, 0, N - 1);
    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0)
        {
            if(b < c)
                cout << Sum(1, 0, N - 1, b-1, c-1) << "\n";
            else
                cout << Sum(1, 0, N - 1, c - 1, b - 1) << "\n";
        }
        else
        {
            long long diff = c - arr[b - 1];
            arr[b - 1] = c;
            Update(1, 0, N - 1, b-1, diff);
        }
    }
    return 0;
}