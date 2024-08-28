#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <stack>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;
int N, M;
long long arr[100000];
vector<long long> tree;
vector<long long> lazy;
long long Make(int node, int start, int end)
{
    if (start == end) {
        tree[node] = arr[start];
        return tree[node];
    }

    int mid = (start + end) / 2;
    long long l = Make(node * 2, start, mid);
    long long r = Make(node * 2 + 1, mid + 1, end);
    tree[node] = l + r;
    return tree[node];
}
void Lazy_Update(int node, int start, int end)
{
    if (lazy[node] != 0)
    {
        tree[node] = tree[node] + (end - start + 1) * lazy[node];
        if (start != end)
        {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}
long long Query(int node, int start, int end, int left, int right)
{
    Lazy_Update(node, start, end);
    if (start > right || end < left) return 0;
    if (left <= start && end <= right) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    long long l = Query(node * 2, start, mid, left, right);
    long long r = Query(node * 2 + 1, mid + 1, end, left, right);
    return l + r;
}
void Update(int node, int start, int end, int left, int right, long long value)
{
    Lazy_Update(node, start, end);
    if (right < start || left > end) return;
    if (left <= start && end <= right)
    {
        tree[node] = tree[node] + (end - start + 1) * value;
        if (start != end) 
        {
            lazy[node * 2] += value;
            lazy[node * 2 + 1] += value;
        }
        return;
    }
    
    int mid = (start + end) / 2;
    Update(node * 2, start, mid, left, right, value);
    Update(node * 2 + 1, mid + 1, end, left, right, value);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int main()
{
    // 노드가 전부 연결, 차수가 홀수인 노드가 0 or 2 개
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> arr[i];
    int height = ceil(log2(N)) + 1;
    tree.resize(1 << height);
    lazy.resize(1 << height);
    Make(1, 0, N - 1);
    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        int p;
        cin >> p;
        if (p == 1) {
            //query
            int a, b, c;
            cin >> a >> b >> c;
            Update(1, 0, N - 1, a - 1, b - 1, c);
        }
        else {
            //update
            int a;
            cin >> a;
            cout << Query(1, 0, N - 1, a - 1, a - 1) << "\n";
        }
    }
    
    return 0;
}