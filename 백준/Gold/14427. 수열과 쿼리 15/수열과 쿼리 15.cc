#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;
int N, K;
vector<int> v;
vector<int> tree;   //node의 index
int Make(int node, int start, int end)
{
    if (start == end) {
        tree[node] = start;
        return start;
    }
    int mid = (start + end) / 2;
    int l = Make(node * 2, start, mid);
    int r = Make(node * 2 + 1, mid + 1, end);
    if (v[l] > v[r]) {
        tree[node] = r;
    }
    else if (v[r] > v[l]){
        tree[node] = l;
    }
    else {
        tree[node] = min(r, l);
    }
    return tree[node];
}
int Get(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return N;
    if (start >= left && end <= right) return tree[node];
    int mid = (start + end) / 2;
    int l = Get(node * 2, start, mid, left, right);
    int r = Get(node * 2 + 1, mid + 1, end, left, right);
    if (l < 0) return r;
    else if (r < 0) return l;
    else {
        if (v[l] > v[r]) return r;
        else if (v[l] < v[r])return l;
        else return min(l, r);
    }
}
int Update(int node, int start, int end, int index) {
    if (start > index || end < index) return tree[node];
    if (start == end) return tree[node];
    int mid = (start + end) / 2;
    int l = Update(node * 2, start, mid, index);
    int r = Update(node * 2 + 1, mid + 1, end, index);
    if (l < 0) return r;
    else if (r < 0) return l;
    if (v[l] > v[r]) {
        tree[node] = r;
    }
    else if (v[l] < v[r]) {
        tree[node] = l;
    }
    else {
        tree[node] = min(l, r);
    }
    return tree[node];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    int a;
    for (int i = 0; i < N; ++i) {
        cin >> a;
        v.push_back(a);
    }
    v.push_back(1987654321);
    int h = ceil(log2(N)) + 1;
    tree.resize(1 << h);
    Make(1, 0, N - 1);

    cin >> K;
    int b, c;
    for (int i = 0; i < K; ++i) {
        cin >> a;
        if (a == 2) {
            cout << Get(1, 0, N - 1, 0, N - 1) + 1 << "\n";
        }
        else {
            cin >> b >> c;
            v[b - 1] = c;
            Update(1, 0, N - 1, b - 1);

        }
    }
    return 0;
}