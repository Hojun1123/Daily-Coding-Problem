#include <iostream>
#include <vector>
#include <map>
#include <deque>
#include <list>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <cstring>
#include <list>
using namespace std;
int N, M;
vector<int> v[32001];
int inArr[32001];
int check[32001];
priority_queue<int, vector<int>, greater<int>> pq;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        inArr[b]++;
    }

    for (int i = 1; i <= N; ++i)
    {
        if (inArr[i]) continue;
        pq.push(i);
    }
    while (!pq.empty())
    {
        int now = pq.top();
        pq.pop();
        cout << now << " ";
        for (int i : v[now])
        {
            inArr[i] --;
            if (inArr[i] == 0)
            {
                pq.push(i);
            }
        }
    }
    return 0;
}
