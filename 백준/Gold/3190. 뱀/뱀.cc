#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <deque>
#include <unordered_map>
#include <cstring>
using namespace std;
// 오른쪽,
//1. 몸길이를 늘려 다음칸에 위치시킴. 만약 자기 자신이나 벽이랑 부딪치면 게임끝
//2. 사과가 있으면 사과가 없어지고 꼬리는 움직이지 않음
//3. 사과가 없다면 몸길이는 변하지 않음
int N, K, L;
int arr[100][100];
int apple[100][100];
struct yx {
    int y, x;
};
map<int, int> dir;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
deque<yx> snake;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    for (int i = 0; i < K; ++i)
    {
        int y, x;
        cin >> y >> x;
        apple[y - 1][x - 1] = 1;
    }
    cin >> L;
    for (int i = 0; i < L; ++i)
    {
        int a; char b;
        cin >> a >> b;
        if (b == 'D')
        {
            dir[a] = 1;
        }
        else
        {
            dir[a] = -1;
        }
    }
    int tCount = 1;
    int DIR = 0;
    arr[0][0] = 1;
    snake.push_back({ 0, 0 });
    while (true)
    {
        int ny = snake.front().y + dy[DIR];   //다음 좌표.
        int nx = snake.front().x + dx[DIR];
        if (ny < 0 || nx < 0 || nx >= N || ny >= N) break;
        if (arr[ny][nx]) break;
        snake.push_front({ ny, nx });
        arr[ny][nx] = 1;
        if (!apple[ny][nx])
        {
            arr[snake.back().y][snake.back().x] = 0;
            snake.pop_back();
        }
        else
        {
            apple[ny][nx] = 0;
        }
        DIR = (4 + DIR + dir[tCount]) % 4;
        tCount++;
    }
    cout << tCount;
    return 0;
}