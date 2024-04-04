#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
using namespace std;
int N, M;
string arr[1000];
struct Node {
    int y, x;
    int cost;
    bool operator<(Node o) const {
        return cost > o.cost;
    }
};
priority_queue<Node> pq;
int answer[1000][1000];
int dx[2] = { 1, -1 };
int EY, EX;
void dijkstra()
{
    while (!pq.empty())
    {
        Node now = pq.top();
        pq.pop();
        if (arr[now.y][now.x] == 'L' && now.y - 1>= 0 && arr[now.y - 1][now.x] != 'X' && arr[now.y - 1][now.x] != 'D')
        {
            //고양이가 사다리인 경우
            int nextCost = answer[now.y][now.x] + 5;
            if (nextCost < answer[now.y - 1][now.x]) {
                answer[now.y - 1][now.x] = nextCost;
                pq.push({now.y - 1, now.x, nextCost});
            }
        }
        
        if (arr[now.y][now.x] != 'X' && now.y + 1 < N && arr[now.y + 1][now.x] == 'L')
        {
            int nextCost = answer[now.y][now.x] + 5;
            if (nextCost < answer[now.y + 1][now.x]) {
                answer[now.y + 1][now.x] = nextCost;
                pq.push({ now.y + 1, now.x, nextCost });
            }
        }

        if (arr[now.y][now.x] == 'X')
        {
            int y = now.y;
            bool isDog = false;
            while (true)
            {
                if (y + 1 >= N) break;
                y += 1;
                if (arr[y][now.x] == 'D') {
                    isDog = true;
                    break;
                }
                else if (arr[y][now.x] != 'X') {
                    break;
                }
            }
            if (!isDog)
            {
                int nextCost = answer[now.y][now.x] + 10;
                if (nextCost < answer[y][now.x]) {
                    answer[y][now.x] = nextCost;
                    pq.push({ y, now.x, nextCost });
                }
            }
        }

        if (arr[now.y][now.x] != 'X') {
            for (int k = 0; k < 2; ++k)
            {
                int x = dx[k] + now.x;
                if (x < 0 || x >= M || arr[now.y][x] == 'D') continue;
                int nextCost = answer[now.y][now.x] + 1;
                if (nextCost >= answer[now.y][x]) continue;
                answer[now.y][x] = nextCost;
                pq.push({ now.y, x, nextCost });
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
        for (int j = 0; j < M; ++j)
        {
            answer[i][j] = 987654321;
            if (arr[i][j] == 'C')
            {
                pq.push({ i, j, 0 });
                answer[i][j] = 0;
                arr[i][j] = 'F';
            }
            else if (arr[i][j] == 'E')
            {
                EY = i;
                EX = j;
                arr[i][j] = 'F';
            }
        }
    }
    dijkstra();
    //for (int i = 0; i < N; ++i) { for (int j = 0; j < M; ++j) cout << answer[i][j] << " "; cout << "\n"; }
    if (answer[EY][EX] > 987654000) cout << "dodo sad";
    else cout << answer[EY][EX];
    return 0;
}