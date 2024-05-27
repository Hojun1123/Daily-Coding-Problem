#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;
int N;
vector<int> v[300001];
int check[300011];
queue<int> q;
int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N - 2; ++i)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    q.push(1);
    check[1] = 1;
    while (!q.empty())
    {
        int nn = q.front();
        q.pop();
        for (int i = 0; i < v[nn].size(); ++i)
        {
            int nxt = v[nn][i];
            if (check[nxt]) continue;
            check[nxt] = 1;
            q.push(nxt);
        }
    }
    int q = 1;
    int p;
    for (int i = 1; i <= N; ++i)
    {
        if (check[i] == 0) {
            p = i;
            break;
        }
    }
    cout << p << " " << q;
    return 0;
 }