#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <unordered_map>
using namespace std;
int N, Q;
struct Dot {
    int k;
    int x1, y1, x2, y2;
};
bool cmpX(Dot a, Dot b)
{
    return a.x1 < b.x1;
}
bool cmpY(Dot a, Dot b)
{
    return a.y1 < b.y1;
}
vector<Dot> arrX;
vector<Dot> arrY;
int uf[200000];
int Find(int n)
{
    if (n == uf[n]) return n;
    int ret = Find(uf[n]);
    uf[n] = ret;
    return ret;
}
void Union(int a, int b)
{
    int r1 = Find(a);
    int r2 = Find(b);
    if (r1 == r2) return;
    if (r1 < r2) uf[r2] = r1;
    else uf[r1] = r2;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> Q;
    int index = 0;
    for (int i = 0; i < N; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a < c) {
            if (b < d) arrX.push_back({i, a, b, c, d });
            else arrX.push_back({i, a, d, c, b });
        }
        else {
            if (b < d) arrX.push_back({i, c, b, a, d });
            else arrX.push_back({i, c, d, a, b });
        }

        if (b < d) {
            if (a < c) arrY.push_back({i, a, b, c, d });
            else arrY.push_back({i, c, b, a, d });
        }
        else {
            if (a < c) arrY.push_back({i, a, d, c, b });
            else arrY.push_back({i, c, d, a, b });
        }
    }
    sort(arrX.begin(), arrX.end(), cmpX);
    sort(arrY.begin(), arrY.end(), cmpY);
    for (int i = 0; i < N; ++i) {
        uf[i] = i;
    }
    int right = arrX[0].x2;
    for (int i = 1; i < N; ++i)
    {
        Dot curr = arrX[i];
        if (curr.x1 <= right)
        {
            right = max(right, curr.x2);
            Union(arrX[i - 1].k, curr.k);
        }
        else {
            right = curr.x2;
        }
    }
    right = arrY[0].y2;
    for (int i = 1; i < N; ++i)
    {
        Dot curr = arrY[i];
        if (curr.y1 <= right)
        {
            right = max(right, curr.y2);
            Union(arrY[i - 1].k, curr.k);
        }
        else {
            right = curr.y2;
        }
    }
    //for (int i = 0; i < N; ++i) cout << uf[i] << " "; cout << "\n";
    for (int i = 0; i < Q; ++i)
    {
        int a, b;
        cin >> a >> b;
        if (Find(a - 1) == Find(b - 1)) cout << "1\n";
        else cout << "0\n";
    }

    return 0;
}