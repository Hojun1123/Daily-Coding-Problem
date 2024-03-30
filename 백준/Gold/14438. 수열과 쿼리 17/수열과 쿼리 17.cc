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
#include <cstring>
using namespace std;
int N;
int arr[100000];
vector<int> tree;
int q[100000][3];
int M;
int Make(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = arr[start];
        return tree[node];
    }
    int mid = (start + end) / 2;
    int l = Make(node * 2, start, mid);
    int r = Make(node * 2 + 1, mid + 1, end);
    tree[node] = min(l, r);
    return tree[node];
}
int Update(int node, int start, int end, int index, int v)
{
    if (index < start || end < index) return tree[node];
    if (start != end)
    {
        int mid = (start + end) / 2;
        int l = Update(node * 2, start, mid, index, v);
        int r = Update(node * 2 + 1, mid + 1, end, index, v);
        tree[node] = min(r, l);
        return tree[node];
    }
    else
    {
        tree[node] = v;
        return v;
    }
}
int Query(int node, int start, int end, int left, int right)
{
    if (left > end || right < start) return 2000000000;
    if (start >= left && end <= right) return tree[node];
    int mid = (start + end) / 2;
    int l = Query(node * 2, start, mid, left, right);
    int r = Query(node * 2 + 1, mid + 1, end, left, right);
    return min(l, r);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> arr[i];
    tree.resize(1 << int(ceil(log2(N)) + 1));
    cin >> M;
    Make(1, 0, N - 1);


    for (int i = 0; i < M; ++i)
    {
        cin >> q[i][0] >> q[i][1] >> q[i][2];
    }


    for (int i = 0; i < M; ++i)
    {
        if (q[i][0] == 1)
        {
            //update
            arr[q[i][1] - 1] = q[i][2];
            Update(1, 0, N - 1, q[i][1] - 1, q[i][2]);

        }
        else
        {
            //print
            cout << Query(1, 0, N - 1, q[i][1] - 1, q[i][2] - 1) << "\n";

        }
    }
    return 0;
}
