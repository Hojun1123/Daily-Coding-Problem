#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <numeric>
#include <stack>
#include <sstream>
#include <queue>
#include <string>

int N, M;
int arr[101][101];

using namespace std;

int main()
{
    // io
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cin >> M;
    int a, b;
    for (int _ = 1; _ <= M; ++_)
    {
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    //BFS
    int answer = 1;
    int minCnt = 10000;
    for (int i = 1; i <= N; ++i)
    {
        queue<int> q;
        int check[101];
        for (int k = 1; k <= N; ++k)
            check[k] = 0;

        q.push(i);
        check[i] = 1;
        int cnt = 0;
        int level = 0;
        while (!q.empty())
        {
            int qs = q.size();
            for (int j = 0; j < qs; ++j)
            {
                int temp = q.front();
                q.pop();
                for (int k = 1; k <= N; ++k)
                {
                    if (arr[temp][k] && check[k] == 0)
                    {
                        check[k] = 1;
                        cnt += level;
                        q.push(k);
                    }
                }
            }
            level++;
        }
        if (cnt < minCnt) {
            minCnt = cnt;
            answer = i;
        }
    }
    cout << answer;
    return 0;
}