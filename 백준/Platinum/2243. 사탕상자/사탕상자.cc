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
int arr[1000001];   //candy
vector<int> tree;
int MakeSegTree(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = arr[start];
        return tree[node];
    }
    int mid = (start + end) / 2;
    int l = MakeSegTree(node * 2, start, mid);
    int r = MakeSegTree(node * 2 + 1, mid + 1, end);
    tree[node] = l + r;
    return tree[node];
}
int Query(int node, int start, int end, int left, int right)
{
    if (left > end || right < start) return 0;
    if (left <= start && right >= end) return tree[node];
    int mid = (start + end) / 2;
    int l = Query(node * 2, start, mid, left, right);
    int r = Query(node * 2 + 1, mid + 1, end, left, right);
    return l + r;
}
void Update(int node, int start, int end, int index, int diff)
{
    if (index < start || index > end) return;
    tree[node] += diff;
    if (start != end)
    {
        int mid = (start + end) / 2;
        Update(node * 2, start, mid, index, diff);
        Update(node * 2 + 1, mid + 1, end, index, diff);
    }
}
int bs(int left, int right, int index)
{
    int mid;
    int sc = -1;
    while (left < right)
    {
        mid = (left + right) / 2;
        int tmp = Query(1, 0, 999999, 0, mid);
        //cout << tmp << ":\n";
        if (tmp >= index)
        {
            right = mid;
            sc = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return sc;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    int h = ceil(log2(1000000)) + 1;
    tree.resize(1 << h);
    MakeSegTree(1, 0, 999999);   //0 ~  999999

    for (int i = 0; i < N; ++i)
    {
        int q, a, b;
        cin >> q;

        //특정 rank에 해당하는 사탕의 인덱스 
        //a ~ b 범위에 대해 사탕의 개수가 mi
        if (q == 1)
        {
            cin >> a;
            int ret = bs(0, 1000000, a);
            cout << ret + 1 << "\n";
            arr[ret] -= 1;
            Update(1, 0, 999999, ret, -1);
        }
        else
        {
            cin >> a >> b;
            arr[a - 1] += b;
            Update(1, 0, 999999, a - 1, b);
        }
    }
    return 0;
}
