#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#include <unordered_map>
#include <regex>
using namespace std;
//재성이는 쎔
//에어프레셔와 바쿰프레스가 있꼬 타임머신이 있음
//재혁이를 i일에 ai의 충격을 주면서 때림
//j일부터 m일까지로 돌아가서 각각 I의 충격을 더해서 때림
//n일부터 m일까지 얼마나 때렸는가?

int N, Q1, Q2;
long long atk[1000001];
vector<long long> tree;
vector<long long> lazy;
long long Make(int node, int start, int end) {
    if (start == end) {
        tree[node] = atk[start];
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
    if (start >= left && end <= right) return tree[node];
    int mid = (start + end) / 2;
    long long l = Query(node * 2, start, mid, left, right);
    long long r = Query(node * 2 + 1, mid + 1, end, left, right);
    return l + r;
}
void Update(int node, int start, int end, int left, int right, long long v) {
    LazyUpdate(node, start, end);
    if (start > right || end < left) return;
    if (start >= left && end <= right) {
        tree[node] = tree[node] + v * (end - start + 1);
        if (start != end) {
            lazy[node * 2] += v;
            lazy[node * 2 + 1] += v;
        }
        return;
    }
    int mid = (end + start) / 2;
    Update(node * 2, start, mid, left, right, v);
    Update(node * 2 + 1, mid + 1, end, left, right, v);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> Q1 >> Q2;
    int h = ceil(log2(N)) + 1;
    tree.resize(1 << h);
    lazy.resize(1 << h);
    for (int i = 1; i <= N; ++i) {
        cin >> atk[i];
    }
    Make(1, 1, N);
    for (int i = 0; i < Q1 + Q2; ++i) {
        int p, a, b, c;
        cin >> p;
        if (p == 1) {
            cin >> a >> b;
            cout << Query(1, 1, N, a, b) << "\n";
        }
        else {
            cin >> a >> b >> c;
            Update(1, 1, N, a, b, c);
        }
    }
    return 0;
}