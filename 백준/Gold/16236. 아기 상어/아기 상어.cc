#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
#include <string>
using namespace std;
int N;
int arr[20][20];
int dy[4] = { -1, 0 ,0, 1 };
int dx[4] = { 0, -1, 1, 0 };
struct yx {
    int y, x;
    bool operator<(yx o) const {
        if (y < o.y) return false;
        else if (y > o.y) return true;
        if (x < o.x) return false;
        else if (x > o.x) return true;
        return false;
    }
};
int babySize = 2;
int by, bx;
int result = 0;
int babyExp = 0;
bool bfs()
{
    int check[20][20];
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            check[i][j] = 0;
        }
    }
    queue<yx> q;
    q.push({ by, bx });
    check[by][bx] = 1;
    int cnt = 0;
    while (!q.empty())
    {
        priority_queue<yx> pq;
        int qSize = q.size();
        for (int i = 0; i < qSize; ++i)
        {
            yx now = q.front();
            q.pop();
            int nowSize = arr[now.y][now.x];
            if (nowSize > 0 && nowSize < babySize)
            {
                pq.push({ now.y, now.x});
            }
            for (int k = 0; k < 4; ++k)
            {
                int y = now.y + dy[k];
                int x = now.x + dx[k];
                if (x >= 0 && y >= 0 && y < N && x < N && check[y][x] == 0 && arr[y][x] <= babySize)
                {
                    check[y][x] = 1;
                    q.push({ y, x });
                }
            }
        }
        if (!pq.empty())
        {
            yx f = pq.top();
            by = f.y;
            bx = f.x;
            arr[by][bx] = 0;
            babyExp++;
            if (babyExp == babySize)
            {
                babyExp = 0;
                babySize++;
            }
            result += cnt;
            return true;
        }
        cnt++;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> arr[i][j];

            if (arr[i][j] == 9)
            {
                by = i;
                bx = j;
                arr[i][j] = 0;
            }
        }
    }
    
    while (true)
    {
        if (bfs())
        {
            //print status
            /*
            cout << "babyPosition : " << by << ", " << bx << "\n";
            cout << "babySize : " << babySize << "\n";
            cout << "result : " << result << "\n";
            for (int i = 0; i < N; ++i)
            {
                for (int j = 0; j < N; ++j)
                {
                    cout << arr[i][j] << " ";
                }
                cout << "\n";
            }
            cout << "\n";
            */
            continue;
        }
        break;
    }
    cout << result;
    return 0;
}