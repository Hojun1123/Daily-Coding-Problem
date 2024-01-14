#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
typedef struct yx {
    int y;
    int x;
} yx;
int dx[4] = { 1, -1, 0 , 0 };
int dy[4] = { 0, 0, 1, -1 };
int N;
int arr[100][100];
int check[100][100];
int main()
{
    int test_case;
    int T;
    string s;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N;
        for (int i = 0; i < N; ++i)
        {
            cin >> s;
            for (int j = 0; j < N; ++j)
            {
                arr[i][j] = s[j] - '0';
            }
        }
        
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                check[i][j] = 10000000;
            }
        }

        queue<yx> q;
        q.push({ 0, 0 });
        check[0][0] = arr[0][0];
        int x, y, xx, yy;
        while (!q.empty())
        {
            y = q.front().y;
            x = q.front().x;
            q.pop();
            for (int k = 0; k < 4; ++k)
            {
                yy = y + dy[k];
                xx = x + dx[k];
                if (xx >= 0 && xx < N && yy >= 0 && yy < N && check[yy][xx] > check[y][x] + arr[yy][xx])
                {
                    q.push({ yy, xx });
                    check[yy][xx] = check[y][x] + arr[yy][xx];
                }
            }
        }

        int a = N - 1;
        cout << "#" << test_case << " " << check[N - 1][N - 1] << "\n";
    }
    return 0;
}