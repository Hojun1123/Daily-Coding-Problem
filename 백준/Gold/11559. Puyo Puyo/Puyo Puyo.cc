#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <unordered_map>
using namespace std;
string arr[12];
int check[12][6];
//rgbpy
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
struct yx {
    int y, x;
};
int result[12][6];
int flag = 1;
void ff(int sy, int sx)
{
    vector<yx> rr;
    char color = arr[sy][sx];
    check[sy][sx] = 1;
    queue<yx> q;
    q.push({ sy, sx });
    while (!q.empty())
    {
        yx now = q.front();
        q.pop();
        rr.push_back(now);
        for (int i = 0; i < 4; ++i)
        {
            int y = dy[i] + now.y;
            int x = dx[i] + now.x;
            if (x < 0 || y < 0 || x >= 6 || y >= 12)continue;
            if (check[y][x]) continue;
            if (color == arr[y][x]) {
                check[y][x] = 1;
                q.push({ y, x });
            }
        }
    }
    if (rr.size() > 3) {
        flag = 1;
        for (int i = 0; i < rr.size(); ++i) {
            result[rr[i].y][rr[i].x] = 1;
        }
    }

    /*
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 6; ++j) cout << result[i][j];
        cout << "\n";
    }cout << "\n";
    */
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 12; ++i)
    {
        cin >> arr[i];
    }

    int ans = 0;
    while (flag) {
        flag = 0;
        memset(check, 0, sizeof(check));
        memset(result, 0, sizeof(result));
        for (int i = 0; i < 12; ++i)
        {
            for (int j = 0; j < 6; ++j)
            {
                if (arr[i][j] == '.' || check[i][j]) continue;
                ff(i, j);
            }
        }

        if (flag == 0) break;

        ans++;
        for (int i = 0; i < 6; ++i) {
            string tmp = "";
            string tmp2 = "";
            for (int j = 0; j < 12; ++j)
            {
                if (result[j][i]) tmp2 += '.';
                else tmp += arr[j][i];
            }
            int index = 0;
            for (int j = 0; j < tmp2.size(); ++j) arr[index++][i] = tmp2[j];
            for (int j = 0; j < tmp.size(); ++j) arr[index++][i] = tmp[j];
        }
    }
    cout << ans;
    return 0;
}