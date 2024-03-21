#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
//1 ~ M 의 번호를 가짐
//1 상어는 가장 강력
// 처음에는 모든 상어가 냄세를 뿌림
//1 초마다 상하좌우로 이동하고 냄세를 뿌림, k번 이동하면 사라짐
//각 상어의 이동 방향은 결정할 때는
//  냄세가 없는 칸
//  자신의 냄새가 있는칸.
//  우선순위
//  위를향할때의 우선순위, 아래를향할때의 우선순위, 왼쪽 오른쪽
// 위아래왼오.
int N, M, K;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
struct Shark {
    int dir[4][4];  //위아래왼오 방향 우선순위.
    int nowDir; //현재 바라보고 있는 방향
    bool isDied;
    int y, x;
    Shark(int a)
    {
        nowDir = a;
    }
};
vector<Shark> shark;
int board[20][20];
struct Smell {
    int sharkNum;
    int t;
};
Smell smellBoard[20][20];
vector<int> sboard[20][20];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < M; ++i)
    {
        int a;
        cin >> a;
        shark.push_back(Shark(a - 1));
        shark[i].isDied = false;
    }
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            for (int k = 0; k < 4; ++k)
            {
                int a;
                cin >> a;
                shark[i].dir[j][k] = a - 1;
            }
        }
    }

    //init
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (board[i][j] == 0) continue;
            smellBoard[i][j] = { board[i][j], K };  // 상어번호, K
            shark[board[i][j] - 1].y = i;
            shark[board[i][j] - 1].x = j;
        }
    }
    // 1. 이동 후 칸에 어떤 상어가 있는지 가지는 벡터.
    // 흔적을 나타내는 벡터.
    int sc;
    for (sc = 0; sc < 1000; ++sc)
    {
        //상어 이동.
        for (int i = 0; i < 20; ++i)
        {
            for (int j = 0; j < 20; ++j)
                sboard[i][j].clear();
        }
        for (int i = 0; i < shark.size(); ++i)
        {
            if (shark[i].isDied) continue;
            bool isMove = false;
            int currDir = shark[i].nowDir;
            for (int k = 0; k < 4; ++k)
            {
                int d = shark[i].dir[currDir][k];
                int y = dy[d] + shark[i].y;
                int x = dx[d] + shark[i].x;
                if (x < 0 || y < 0 || x >= N || y >= N) continue;
                if (smellBoard[y][x].sharkNum > 0) continue;
                // 냄새없는경우
                isMove = true;
                shark[i].nowDir = d;
                shark[i].y = y;
                shark[i].x = x;
                // y x 에 pushback 상어
                sboard[y][x].push_back(i);
                break;
            }
            if (isMove) continue;
            for (int k = 0; k < 4; ++k)
            {
                int d = shark[i].dir[currDir][k];
                int y = dy[d] + shark[i].y;
                int x = dx[d] + shark[i].x;
                if (x < 0 || y < 0 || x >= N || y >= N) continue;
                if (smellBoard[y][x].sharkNum == i + 1)
                {
                    // 본인의 냄새
                    shark[i].nowDir = d;
                    shark[i].y = y;
                    shark[i].x = x;
                    // y x 에 pushback 상어
                    sboard[y][x].push_back(i);
                    break;
                }
            }
        }

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (sboard[i][j].size() < 2) continue;
                int minNum = 987654321;

                for (int k : sboard[i][j])
                {
                    minNum = min(minNum, k);
                    shark[k].isDied = true;
                }
                shark[minNum].isDied = false;
            }
        }
        
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (smellBoard[i][j].t > 0) {
                    smellBoard[i][j].t--;
                    if(smellBoard[i][j].t == 0) smellBoard[i][j].sharkNum = 0;
                }
            }
        }

        int aliveShark = 0;
        for (int i = 0; i < shark.size(); ++i)
        {
            if (shark[i].isDied) continue;
            smellBoard[shark[i].y][shark[i].x] = { i + 1, K };
            aliveShark++;
        }
        if (aliveShark == 1) break;
        /*
        cout << "sc : \n";
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j) cout << smellBoard[i][j].t << " ";
            cout << "\n";
        }
        */
    }
    cout << (sc == 1000 ? -1 : sc + 1);
    return 0;
}