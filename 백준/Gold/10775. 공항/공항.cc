#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;
int G, P;
int airplane[100001];
int arr[100001];
int check[100001];
void init()
{
    for (int i = 0; i <= G; ++i)
        arr[i] = i;
}
int Find(int n)
{
    if (n == arr[n]) return n;
    int ret = Find(arr[n]);
    arr[n] = ret;
    return ret;
}
void Union(int a, int b)
{
    int r1 = Find(a);
    int r2 = Find(b);
    if (r1 == r2) return;
    arr[r2] = r1;
}
int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin >> G >> P;
    for (int i = 0; i < P; ++i)
    {
        cin >> airplane[i];
    }
    init();
    int cnt = 0;
    for (int i = 0; i < P; ++i)
    {
        int curr = airplane[i];
        bool flag = false;
        for (int j = curr; j > 0; --j)
        {
            int now = Find(j);
            if (check[now] == 0)
            {
                cnt++;
                flag = true;
                check[now] = 1;
                if (check[now - 1])
                {
                    Union(now - 1, now);
                }
                if (check[now + 1])
                {
                    Union(now, now + 1);
                }
                break;
            }
            j = now;
        }
        if (!flag) break;
    }
    cout << cnt;
    return 0;
}