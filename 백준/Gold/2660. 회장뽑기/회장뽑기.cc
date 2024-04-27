#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;
int N;
int graph[51][51];
int answer[51][51];
int maxValue[51];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (i == j) continue;
            answer[i][j] = 987654321;
        }
    }

    while (1) {
        int a, b;
        cin >> a >> b;
        if (a == -1 || b == -1) break;
        answer[b][a] = 1;
        answer[a][b] = 1;
    }
    //1 : 다른 모든 회원과 친구
    //2 : 다른 모든 회원이 친구이거나 or 친구의 친구
    //3 : 1 , 2 친구의 친구의 친구.
    // 4, 5...
    
    //cost = 1

    for (int k = 1; k <= N; ++k)
    {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                int tmp = answer[i][k] + answer[k][j];
                answer[i][j] = min(answer[i][j], tmp);
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            maxValue[i] = max(maxValue[i], answer[i][j]);
        }
    }
    int minValue = 987654321;
    for (int i = 1; i <= N; ++i) {
        minValue = min(minValue, maxValue[i]);
    }

    int cnt = 0;
    queue<int> q;
    for (int i = 1; i <= N; ++i) {
        if (minValue - maxValue[i]) continue;
        cnt++;
        q.push(i);
    }
    cout << minValue << " " << cnt << "\n";
    while (!q.empty()) {
        cout << q.front() << " "; q.pop();
    }

    return 0;
}