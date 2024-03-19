#include <vector>
#include <cmath>
#include <iostream>
#include <stack>
#include <queue>
#include <cstring>
#include <map>
#include <unordered_map>
using namespace std;
int T;
int N, K;
int arr[100001];
vector<int> segTree;
int Make(int node, int start, int end)
{
    if (start == end)
    {
        if (arr[start] > 0)
            segTree[node] = 1;
        else if (arr[start] < 0)
            segTree[node] = -1;
        else
            segTree[node] = 0;
        return segTree[node];
    }
    int mid = (start + end) / 2;
    int l = Make(node * 2, start, mid);
    int r = Make(node * 2 + 1, mid + 1, end);
    int s = l * r;
    if (s > 0) segTree[node] = 1;
    else if (s < 0) segTree[node] = -1;
    else segTree[node] = 0;
    return segTree[node];
}
int getResult(int node, int start, int end, int left, int right)
{
    if (left > end || right < start) return 1;
    if (left <= start && right >= end) return segTree[node];
    int mid = (start + end) / 2;
    int l = getResult(node * 2, start, mid, left, right);
    int r = getResult(node * 2 + 1, mid + 1, end, left, right);
    int s = l * r;
    if (s > 0) return 1;
    else if (s < 0) return -1;
    else return 0;
}
int Update(int node, int start, int end, int index, int diff)
{
    if (index < start || index > end) return segTree[node];
    if (start != end)
    {
        int mid = (start + end) / 2;
        int l = Update(node * 2, start, mid, index, diff);
        int r = Update(node * 2 + 1, mid + 1, end, index, diff);
        int s = l * r;
        if (s > 0) s = 1;
        else if (s < 0) s = -1;
        else s = 0;
        segTree[node] = s;
    }
    else {
        segTree[node] = diff;
    }
    return segTree[node];
}
void solve()
{
    string pp = "";
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }
    int h = ceil(log2(N)) + 1;
    segTree.clear();
    segTree.resize(1 << h);
    Make(1, 0, N - 1);
    for (int i = 0; i < K; ++i)
    {
        char a;
        int b, c;
        //for(int k : segTree) cout << k << " ";
        //cout<<"\n";
        cin >> a >> b >> c;
        if (a == 'C')
        {
            if (c > 0) c = 1;
            else if (c < 0) c = -1;
            else c = 0;
            arr[b - 1] = c;
            Update(1, 0, N - 1, b - 1, c);
        }
        else
        {
            int re = getResult(1, 0, N - 1, b - 1, c - 1);
            if (re == 0) pp += '0';
            else pp += (re > 0 ? '+' : '-');
        }
    }
    cout << pp << "\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (cin>>N >> K)
    {
        solve();
    }
    return 0;
}