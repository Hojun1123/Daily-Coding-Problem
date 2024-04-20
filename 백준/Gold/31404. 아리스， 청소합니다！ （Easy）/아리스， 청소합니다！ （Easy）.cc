#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <cmath>
#include <unordered_map>
using namespace std;
int H, W;
int R, C, D;
int A[1024][1024];
int B[1024][1024];
int visited[1024][1024][4];
int arr[1024][1024];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
struct yx {
    int y, x;
};
struct Node {
    //y, x, 최종 방향
    int y, x, d;
    bool operator==(Node o) const {
        return o.y == y && o.x == x && o.d == d;
    }
};
//a방향으로 y x 좌표에 접근할때 Node로 이동.
Node warp[1024][1024][4];
int warpCost[1024][1024][4];
stack<Node> memory;
void init()
{
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            //d로 들어올 때 y , x 로 나감.
            for (int k = 0; k < 4; ++k)
            {
                //처음에는 입력값 = 값
                warp[i][j][k] = { i, j, k };
                warpCost[i][j][k] = 0;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> H >> W;
    cin >> R >> C >> D;
    for (int i = 0; i < H; ++i)
    {
        string a;
        cin >> a;
        for (int j = 0; j < W; ++j)
        {
            A[i][j] = a[j] - '0';
        }
    }
    for (int i = 0; i < H; ++i)
    {
        string a;
        cin >> a;
        for (int j = 0; j < W; ++j)
        {
            B[i][j] = a[j] - '0';
        }
    }
    init();

    //해당 칸이 아직 청소 X
    //해당 칸이 청소o, 해당 칸에 들어오는 방향으로 체크
    //청소하면 1
    int x, y, prevX, prevY, d, prevD;
    x = C;
    y = R;
    d = D;
    int answer = 0;
    int cnt = 0;
    int cleanCnt = 0;
    while (true)
    {
        prevX = x;
        prevY = y;
        prevD = d;
        //cout <<"\n" << cnt << " : " << y << ", " << x << "\n";

        if (arr[y][x])
        {
            //B, warp 수행
            memory.push({ y, x, d });  //청소가 이미 되있음 -> 저장소에 push
            if (warpCost[y][x][d] > 0)
            {
                Node w = warp[y][x][d];
                cnt += warpCost[y][x][d];
                //cout << "wp : " << y << "," << x << "," << d << " to " << w.y << "," << w.x << "," << w.d << " : " << warpCost[y][x][d] << "\n";
                y = w.y;
                x = w.x;
                d = w.d;
            }
            cnt++;

            if (visited[y][x][d] == cleanCnt) break;    //반복되었으나 청소한 영역x
            visited[y][x][d] = cleanCnt;    //check업데이트
            d = (B[y][x] + d) % 4;
            y = dy[d] + y;
            x = dx[d] + x;
            if (x < 0 || y < 0 || x >= W || y >= H) break;  //영역 check
        }
        else
        {
            //A
            arr[y][x] = 1;
            int wc = warpCost[y][x][d] + 1;
            while (!memory.empty())
            {
                int yy = memory.top().y;
                int xx = memory.top().x;
                int dd = memory.top().d;
                warp[yy][xx][dd] = warp[y][x][d];
                warpCost[yy][xx][dd] += wc;
                wc = warpCost[yy][xx][dd] + 1;
                //cout << "save : " << yy << " " << xx << " " << dd << " to " << y << " " << x << " " << d << ": " << wc << "\n";
                memory.pop();
            }
            d = (A[y][x] + d) % 4;  //방향 갱신하고, yx 계산
            y = dy[d] + y;
            x = dx[d] + x;
            cleanCnt++;  //청소개수 + 1
            answer = cnt;   //청소가 이루어졌다면 반영.
            cnt++;
            if (x < 0 || y < 0 || x >= W || y >= H) break;  //영역 check
        }
    }
    cout << answer + 1;
    return 0;
}