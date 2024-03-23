#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <string>
#include <unordered_map>
#include <bitset>
#include <stack>
#include <unordered_set>
#include <set>
using namespace std;
int arr[1000000];
vector<int> segmentTree;
int M, N;
int Make(int node, int start, int end)
{
    if (start == end)
    {
        segmentTree[node] = arr[start];
        return segmentTree[node];
    }
    int mid = (start + end) / 2;
    int l = Make(node * 2, start, mid);
    int r = Make(node * 2 + 1, mid + 1, end);
    segmentTree[node] = max(l, r);
    return segmentTree[node];
}
int getValue(int node, int start, int end, int left, int right)
{
    if (start > right || end < left) return 0;
    if (start >= left && end <= right) return segmentTree[node];
    int mid = (start + end) / 2;
    int l = getValue(node * 2, start, mid, left, right);
    int r = getValue(node * 2 + 1, mid + 1, end, left, right);
    return max(l, r);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }
    int h = ceil(log2(N)) + 1;
    segmentTree.resize(1 << h);
    Make(1, 0, N - 1);
    for (int i = M - 1; i <= N - M; ++i)
    {
        //int l = i - M + 1;
        //int r = i + M - 1;
        cout << getValue(1, 0, N - 1, i - M + 1, i + M - 1) << " ";
    }
    return 0;
}