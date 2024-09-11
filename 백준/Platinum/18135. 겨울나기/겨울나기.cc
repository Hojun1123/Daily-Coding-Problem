#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
int N, M;
vector<long long> tree;
vector<long long> lazy;
int num[2000001];
long long arr[1000001];
long long Make(int node, int start, int end) {
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
void LazyUpdate(int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node] = tree[node] + lazy[node] * (end - start + 1);
        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}
long long Query(int node, int start, int end, int left, int right) {
    LazyUpdate(node, start, end);
    if (left > end || right < start) return 0;
    if (left <= start && right >= end) return tree[node];
    int mid = (start + end) / 2;
    long long l = Query(node * 2, start, mid, left, right);
    long long r = Query(node * 2 + 1, mid + 1, end, left, right);
    return l + r;
}
void Update(int node, int start, int end, int left, int right, long long value) {
    LazyUpdate(node, start, end);
    if (start > right || end < left) return;
    if (start >= left && end <= right) {
        tree[node] = tree[node] + value * (end - start + 1);
        if (start != end) {
            lazy[node * 2] += value;
            lazy[node * 2 + 1] += value;
        }
        return;
    }
    int mid = (end + start) / 2;
    Update(node * 2, start, mid, left, right, value);
    Update(node * 2 + 1, mid + 1, end, left, right, value);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    int h = ceil(log2(M)) + 1;
    tree.resize(1 << h);
    lazy.resize(1 << h);
    memset(num, -1, sizeof(num));
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        for (int j = a; j <= b; ++j) {
            //j번칸은 i 영역.
            num[j - 1] = i;
            arr[i] = c;
        }
    }
    Make(1, 0, M - 1);
    while (true) {
        int a, b, c, d;
        cin >> a >> b >> c;
        if (a == 0) break;
        else if (a == 1) {
            long long ret = 0;
            if (b <= c) {
                ret += Query(1, 0, M - 1, num[b - 1], num[c - 1]);
            }
            else {
                ret += Query(1, 0, M - 1, num[b - 1], M - 1);
                ret += Query(1, 0, M - 1, 0, num[c - 1]);
            }
            cout << ret << "\n";
        }
        else {
            cin >> d;
            if (b <= c ) {
                Update(1, 0, M - 1, num[b - 1], num[c - 1], d);
            }
            else {
                Update(1, 0, M - 1, num[b - 1], M - 1, d);
                Update(1, 0, M - 1, 0, num[c - 1], d);
            }
        }
    }
}