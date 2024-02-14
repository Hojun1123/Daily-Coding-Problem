#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <vector>
using namespace std;
int N;
int arr[125][125];
int answer[125][125];
int dy[4] = { 1, -1, 0, 0 }; int dx[4] = { 0, 0, 1, -1 };
struct yx {
    int y, x, cost;
    bool operator<(yx o) const {
        return cost > o.cost;
    }
};
void solve()
{
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j)
            answer[i][j] = 987654321;
    }
    priority_queue<yx> pq;
    pq.push({0, 0, arr[0][0] });
    answer[0][0] = arr[0][0];
    while (!pq.empty()) {
        yx now = pq.top(); pq.pop();
        for (int i = 0; i < 4; ++i){
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            int nextCost = answer[now.y][now.x] + arr[ny][nx];
            if (nextCost >= answer[ny][nx]) continue;
            answer[ny][nx] = nextCost;
            pq.push({ ny, nx, nextCost });
        }
    }
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int tc = 1;
    while (true)
    {
        cin >> N;
        if (N == 0)
        {
            break;
        }
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                cin >> arr[i][j];
            }
        }
        solve();
        cout << "Problem " << tc << ": " << answer[N - 1][N - 1] << "\n";
        tc++;
    }
    return 0;
}