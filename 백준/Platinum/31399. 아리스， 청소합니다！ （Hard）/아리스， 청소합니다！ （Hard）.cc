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
long long visited[1024][1024][4];
int arr[1024][1024];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
struct yx {
    int y, x;
};
struct Node {
    int y, x, d;
    bool operator==(Node o) const {
        return o.y == y && o.x == x && o.d == d;
    }
};
Node warp[1024][1024][4];
long long warpCost[1024][1024][4];
stack<Node> memory;
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
        for (int j = 0; j < W; ++j) A[i][j] = a[j] - '0';
    }
    for (int i = 0; i < H; ++i)
    {
        string a;
        cin >> a;
        for (int j = 0; j < W; ++j) B[i][j] = a[j] - '0';
    }
    //init
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
    //simulation
    int x = C, y = R, d = D;
    long long answer = 0;
    long long cnt = 0;
    long long cleanCnt = 0;
    while (true)
    {
        if (arr[y][x])
        {
            //B, warp 수행
            memory.push({ y, x, d });  //청소가 이미 되있음 -> 저장소에 push
            if (warpCost[y][x][d] > 0)
            {
                Node w = warp[y][x][d];
                cnt += warpCost[y][x][d];
                y = w.y;
                x = w.x;
                d = w.d;
            }
            cnt++;

            if (visited[y][x][d] == cleanCnt) break;    //반복되었으나 청소한 영역x
            visited[y][x][d] = cleanCnt;    //check업데이트
            d = (B[y][x] + d) % 4;
            y += dy[d];
            x += dx[d];
            if (x < 0 || y < 0 || x >= W || y >= H) break;  //영역 check
        }
        else
        {
            //A
            arr[y][x] = 1;
            long long wc = warpCost[y][x][d] + 1;
            while (!memory.empty())
            {
                Node tmp = memory.top();
                memory.pop();
                warp[tmp.y][tmp.x][tmp.d] = warp[y][x][d];  //warp 지점 재설정
                warpCost[tmp.y][tmp.x][tmp.d] += wc;    //warp 비용 재설정
                wc = warpCost[tmp.y][tmp.x][tmp.d] + 1; //다음칸에 대해 워프비용 재계산
            }
            d = (A[y][x] + d) % 4;  //방향 갱신하고, yx 계산
            y += dy[d];
            x += dx[d];
            cleanCnt++;  //청소개수 + 1
            answer = cnt++;   //청소가 이루어졌다면 반영 후 증가
            if (x < 0 || y < 0 || x >= W || y >= H) break;  //영역 check
        }
    }
    cout << answer + 1;
    return 0;
}