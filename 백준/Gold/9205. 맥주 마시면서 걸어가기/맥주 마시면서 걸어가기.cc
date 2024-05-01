#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <cmath>
#include <unordered_map>
#include <cstring>
#include <algorithm>
using namespace std;
//한 박스에는 맥주가 20 개
// 50미터에 한 병씩. -> 49미터에서는 하나 마시고 50
// 집 편의점 락 페스티벌.
int T, N;
struct yx {
    int y, x;
};
int sy, sx, dy, dx;
yx arr[101];
int check[101];
void solve()
{
    queue<yx> q;
    memset(check, 0, sizeof(check));
    cin >> N;
    cin >> sx >> sy;
    for (int i = 1; i <= N; ++i) cin >> arr[i].x >> arr[i].y;
    cin >> dx >> dy;
    q.push({ sy, sx});
    check[0] = 1;   //0, 20
    while (!q.empty()) {
        int qSize = q.size();
        for (int i = 0; i < qSize; ++i) {
            yx now = q.front();
            q.pop();
            if ((abs(now.y - dy) + abs(now.x - dx)) <= 1000) {
                cout << "happy\n";
                return;
            }
            for (int k = 1; k <= N; ++k) {
                int distance = abs(now.y - arr[k].y) + abs(now.x - arr[k].x);
                if (distance > 1000) continue;
                if (check[k]) continue;
                check[k] = 1;
                q.push({ arr[k].y, arr[k].x });
            }
        }
    }
    cout << "sad\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    for (int i = 0; i < T; ++i) solve();
    return 0;
}