#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <cmath>
#include <unordered_map>
#include <cstring>
#include <algorithm>
using namespace std;
int N, Q;
int arr[100001];
vector<int> tree;
int Make(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = start;
        return start;
    }
    int mid = (start + end) / 2;
    int l = Make(node * 2, start, mid);
    int r = Make(node * 2 + 1, mid + 1, end);
    if (arr[l] < arr[r]) tree[node] = l;
    else if (arr[r] < arr[l]) tree[node] = r;
    else tree[node] = min(l, r);
    return tree[node];
}
int Query(int node, int start, int end, int left, int right)
{
    if (left > end || right < start) return N;
    if (left <= start && right >= end) return tree[node];
    int mid = (start + end) / 2;
    int l = Query(node * 2, start, mid, left, right);
    int r = Query(node * 2 + 1, mid + 1, end, left, right);
    if (arr[l] < arr[r]) return l;
    else if (arr[l] > arr[r]) return r;
    else return min(l, r);
}
int Update(int node, int start, int end, int index)
{
    if (start > index || end < index) return tree[node];
    if (start != end)
    {
        int mid = (start + end) / 2;
        int l = Update(node * 2, start, mid, index);
        int r = Update(node * 2 + 1, mid + 1, end, index);
        if (arr[l] < arr[r]) tree[node] = l;
        else if (arr[l] > arr[r]) tree[node] = r;
        else tree[node] = min(l, r);
        return tree[node];
    }
    else return start;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    int h = ceil(log2(N)) + 1;
    tree.resize(1 << h);
    Make(1, 0, N - 1);
    arr[N] = 2100000000;
    cin >> Q;
    int a, b, c;
    //for (int j = 1; j <= 15; ++j) cout << tree[j] << " ";
    //cout << "\n";
    for (int i = 0; i < Q; ++i)
    {
        cin >> a >> b >> c;
        if (a == 1) {
            //update
            arr[b - 1] = c;
            //Make(1, 0, N - 1);
            Update(1, 0, N - 1, b - 1);
        }
        else {
            //print
            cout << Query(1, 0, N - 1, b - 1, c - 1) + 1 << "\n";
        }
    }
    return 0;
}