#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <stack>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
using namespace std;
vector<int> tree;
void func(int start, int end)
{
    if (start >= end) return;
    int i;
    for (i = start + 1; i < end; ++i)
        if (tree[start] < tree[i]) break;
    func(start + 1, i);
    func(i, end);
    cout << tree[start] << "\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a;
    while (cin >> a) {
        tree.push_back(a);
    }
    func(0, tree.size());
    return 0;
}