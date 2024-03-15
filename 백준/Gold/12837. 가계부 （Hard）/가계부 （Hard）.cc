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
vector<long long> segTree;
int N, Q;
long long Sum(int node, int start, int end, int left, int right)
{
    if (start > right || left > end) return 0;
    if (start >= left && end <= right) return segTree[node];
    int mid = (start + end) / 2;
    long long leftSum = Sum(node * 2, start, mid, left, right);
    long long rightSum = Sum(node * 2 + 1, mid + 1, end, left, right);
    return leftSum + rightSum;
}
void Update(int node, int start, int end, int index, long long diff)
{
    if (index < start || index > end) return;
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
    cin >> N >> Q;
    int h = ceil(log2(N)) + 1;
    segTree.resize(1 << h);
    for (int i = 0; i < Q; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1)
        {
            Update(1, 0, N - 1, b - 1, c);
        }
        else
        { 
            cout << Sum(1, 0, N - 1, b - 1, c - 1) << "\n";
        }
    }

    return 0;
}