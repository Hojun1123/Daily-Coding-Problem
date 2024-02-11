#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
#include <string>
using namespace std;
int N, M, K;
struct Bus {
    int x1, y1, x2, y2;
    int t;
    Bus() {};
    Bus(int a, int b, int c, int d)
    {
        if (a == c)
        {
            //수직
            t = 1;
            x1 = a;
            x2 = c;
            if (b < d)
            {
                y1 = b;
                y2 = d;
            }
            else
            {
                y1 = d;
                y2 = b;
            } 
        }
        else
        {
            //수평
            t = 0;
            y1 = b;
            y2 = d;
            if (a < c)
            {
                x1 = a;
                x2 = c;
            }
            else
            {
                x1 = c;
                x2 = a;
            }
        }
    }
};
Bus bus[5001];
vector<int> graph[5001];
int check[5001];
int sx, sy, dx, dy;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> M >> N;
    cin >> K;
    for (int i = 0; i < K; ++i) {
        int n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;
        bus[n] = Bus(a, b, c, d);
    }
    cin >> sx >> sy >> dx >> dy;

    for (int i = 1; i < K; ++i)
    {
        for (int j = i + 1; j <= K; ++j)
        {
            if (i == j) continue;
            if (bus[i].t)
            {
                if (bus[j].t)
                {
                    //1. 수직, 수직
                    if (bus[i].x1 != bus[j].x1) continue;
                    if (bus[i].y1 < bus[j].y1)
                    {
                        if (bus[j].y1 <= bus[i].y2)
                        {
                            graph[i].push_back(j);
                            graph[j].push_back(i);
                        }
                    }
                    else
                    {
                        if(bus[i].y1 <= bus[j].y2)
                        {
                            graph[i].push_back(j);
                            graph[j].push_back(i);
                        }
                    }
                }
                else
                {
                    //2.수직, 수평
                    if (bus[j].y1 >= bus[i].y1 && bus[j].y1 <= bus[i].y2 && bus[i].x1 >= bus[j].x1 && bus[i].x1 <= bus[j].x2)
                    {
                        graph[i].push_back(j);
                        graph[j].push_back(i);
                    }
                }
            }
            else
            {
                if (bus[j].t)
                {
                    if (bus[i].y1 >= bus[j].y1 && bus[i].y1 <= bus[j].y2 && bus[j].x1 >= bus[i].x1 && bus[j].x1 <= bus[i].x2)
                    {
                        graph[i].push_back(j);
                        graph[j].push_back(i);
                    }
                    //3.수평, 수직
                }
                else
                {
                    //4. 수평, 수평
                    if (bus[i].y1 != bus[j].y1) continue;
                    if (bus[i].x1 < bus[j].x1)
                    {
                        if (bus[j].x1 <= bus[i].x2)
                        {
                            graph[i].push_back(j);
                            graph[j].push_back(i);
                        }
                    }
                    else
                    {
                        if (bus[i].x1 <= bus[j].x2)
                        {
                            graph[i].push_back(j);
                            graph[j].push_back(i);
                        }
                    }
                }
            }
        }
    }

    queue<int> q;
    map<int, int> des;
    for (int i = 1; i <= K; ++i)
    {
        Bus now = bus[i];
        if (sx >= now.x1 && sx <= now.x2 && sy >= now.y1 && sy <= now.y2)
        {
            check[i] = 1;
            q.push(i);
        }

        if (dx >= now.x1 && dx <= now.x2 && dy >= now.y1 && dy <= now.y2)
        {
            des[i] = 1;
        }
    }

    int cnt = 1;
    while (!q.empty())
    {
        int qSize = q.size();
        for (int i = 0; i < qSize; ++i)
        {
            int now = q.front();
            q.pop();
            if (des[now])
            {
                cout << cnt;
                return 0;
            }
            for (int j : graph[now])
            {
                if (check[j] == 0)
                {
                    q.push(j);
                    check[j] = 1;
                }
            }
        }
        cnt++;
    }
    return 0;
}