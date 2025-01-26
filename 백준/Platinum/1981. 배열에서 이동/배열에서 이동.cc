#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;
int N, M;
int arr[100][100];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
struct yx {
    int y, x;
};
int visited[100][100];
int bfs(int minValue, int th)
{
    if (th < arr[0][0]) return 0;
    queue<yx> q;
    memset(visited, 0, sizeof(visited));
    q.push({ 0, 0 });
    visited[0][0] = 1;
    while (!q.empty()) {
        int qSize = q.size();
        for (int i = 0; i < qSize; ++i) {
            yx now = q.front();
            q.pop();
            if (now.y == N - 1 && now.x == N - 1) {
                
                /*for (int z = 0; z < N; ++z) {
                    for (int a = 0; a < N; ++a) cout << visited[z][a] << " "; cout << "\n";
                }
                cout << "\n";*/
                
                return 1;
            }
            for (int k = 0; k < 4; ++k) {
                int y = dy[k] + now.y;
                int x = dx[k] + now.x;
                if (x < 0 || y < 0 || x >= N || y >= N) continue;
                if (visited[y][x]) continue;
                if ((arr[y][x] < minValue) || (th < arr[y][x])) continue;
                visited[y][x] = 1;
                q.push({ y, x,});
            }
        }
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    int sValue = 200;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> arr[i][j];
            sValue = min(arr[i][j], sValue);
        }
    }
    //200 * logN * 10000 -> 200 00000

    int ans = 200;
    for (int i = sValue; i <= arr[0][0]; ++i) {
        int left = i;
        int right = 201;
        //min
        while (left < right) {
            int mid = (left + right) / 2;
            if (bfs(i, mid)) {
                //cout <<i << "," << mid <<": " << ans << "-> " << mid - i << "\n";
                ans = min(mid - i, ans);
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
    }
    cout << ans;

    return 0;
}