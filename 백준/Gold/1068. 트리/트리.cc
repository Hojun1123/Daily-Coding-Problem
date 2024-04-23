#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;
int N,K;
int root;
int cnt = 0;
vector<int> tree[55];
int tmp[55];
void dfs(int n)
{
    if (tree[n].size() == 0) { 
        //cout << n << " ";
        cnt++; 
    }
    for (int i = 0; i < tree[n].size(); ++i) {
        dfs(tree[n][i]);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> tmp[i];
    }
    cin >> K;
    for (int i = 0; i < N; ++i)
    {
        if (tmp[i] == -1) root = i;
        else if(tmp[i] != K && i != K) tree[tmp[i]].push_back(i);
    }
    if(root != K)
        dfs(root);
    cout << cnt;
    return 0;
}