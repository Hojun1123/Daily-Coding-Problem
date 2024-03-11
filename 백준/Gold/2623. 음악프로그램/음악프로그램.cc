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
vector<int> graph[1001];
int isAble[1001];
vector<int> result;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int n, prev;
        cin >> n >> prev;
        for (int j = 1; j < n; ++j)
        {
            int curr;
            cin >> curr;
            graph[prev].push_back(curr);
            isAble[curr] ++;
            prev = curr;
        }
    }

    queue<int> q;
    for (int i = 1; i <= N; ++i)
    {
        if (isAble[i]) continue;
        q.push(i);
        result.push_back(i);
    }

    while (!q.empty())
    {
        int qSize = q.size();
        for (int i = 0; i < q.size(); ++i)
        {
            int now = q.front(); q.pop();
            for (int k : graph[now])
            {
                isAble[k] --;
                if (isAble[k] == 0)
                {
                    result.push_back(k);
                    q.push(k);
                }
                else if (isAble[k] < 0)
                {
                    cout << 0; return 0;
                }
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        if (isAble[i] > 0) {
            cout << 0;
            return 0;
        }
    }
    for (int i : result)
        cout << i << "\n";
    return 0;
}
