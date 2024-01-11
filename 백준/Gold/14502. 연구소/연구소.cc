#include <iostream>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
int N, M;
int arr[8][8];
int check[8][8];
int answer = 0;
typedef struct yx {
    int y;
    int x;
} yx;
vector<yx> wallVec;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int ax[4] = { 1, -1, 0, 0 };
    int ay[4] = { 0, 0 , 1, -1 };
    int input;
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> input;
            arr[i][j] = input;
            if (input == 0)
                wallVec.push_back({ i, j });
        }
    }

    yx w1, w2, w3;
    for (int _ = 0; _ < wallVec.size() - 2; ++_)
    {
        w1 = wallVec[_];
        arr[w1.y][w1.x] = 1;
        for (int _2 = _ + 1; _2 < wallVec.size() - 1; ++_2)
        {
            w2 = wallVec[_2];
            arr[w2.y][w2.x] = 1;
            for (int _3 = _2 + 1; _3 < wallVec.size(); ++_3)
            {
                w3 = wallVec[_3];
                arr[w3.y][w3.x] = 1;
                for (int i = 0; i < N; ++i)
                {
                    for (int j = 0; j < M; ++j)
                    {
                        check[i][j] = 0;
                    }
                }

                int x, y, dx, dy;
                for (int i = 0; i < N; ++i)
                {
                    for (int j = 0; j < M; ++j)
                    {
                        if (arr[i][j] == 2 && check[i][j] == 0)
                        {
                            stack<yx> s;
                            s.push({ i, j });
                            check[i][j] = 1;
                            while (!s.empty())
                            {
                                y = s.top().y;
                                x = s.top().x;
                                s.pop();
                                for (int k = 0; k < 4; ++k)
                                {
                                    dy = y + ay[k];
                                    dx = x + ax[k];
                                    if (dy >= 0 && dy < N && dx >= 0 && dx < M && arr[dy][dx] == 0 && check[dy][dx] == 0)
                                    {
                                        s.push({ dy, dx });
                                        check[dy][dx] = 1;
                                    }
                                }
                            }

                        }
                    }
                }
                int cnt = 0;
                for (int i = 0; i < N; ++i)
                {
                    for (int j = 0; j < M; ++j)
                    {
                        if (arr[i][j] == 0 && check[i][j] == 0)
                            cnt++;
                    }
                }
                if (answer < cnt)
                    answer = cnt;
                arr[w3.y][w3.x] = 0;
            }
            arr[w2.y][w2.x] = 0;
        }
        arr[w1.y][w1.x] = 0;
    }
    cout << answer;
}