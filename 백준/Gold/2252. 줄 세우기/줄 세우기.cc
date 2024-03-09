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
queue<int> q;
queue<int> r;
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
        if (inArr[i] == 0) {
            q.push(i);
            r.push(i);
        }

    }

    while (!q.empty())
    {
        int qSize = q.size();
        for (int i = 0; i < qSize; ++i)
        {
            int now = q.front();
            q.pop();
            for (int k : v[now])
            {
                inArr[k] --;
                if (inArr[k] == 0)
                {
                    r.push(k);
                    q.push(k);
                }
            }
        }
    }
    while (!r.empty()) { cout << r.front() << " "; r.pop(); }
    return 0;
}
