#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <string>
#include <unordered_map>
#include <bitset>
#include <stack>
#include <unordered_set>
#include <cstring>
using namespace std;
struct xy {
    long long x, y;
};
long long cross(xy a, xy b)
{
    long long r = (a.x * b.y - a.y * b.x);
    if (r == 0) return 0;
    else if (r > 0) return 1;
    else return  -1;
}
bool check(long long a1, long long a2, long long a3, long long a4)
{
    if (a1 <= a4 && a3 <= a2) return true;
    if (a3 <= a2 && a1 <= a4) return true;
    return false;
}
bool solve()
{
    long long x1, y1, x2, y2;
    long long x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    xy l12 = { x2 - x1, y2 - y1 };
    xy l23 = { x3 - x2, y3 - y2 };
    xy l24 = { x4 - x2, y4 - y2 };

    xy l43 = { x3 - x4, y3 - y4 };
    xy l31 = { x1 - x3, y1 - y3 };
    xy l32 = { x2 - x3, y2 - y3 };

    long long r1 = cross(l12, l23) * cross(l12, l24);
    long long r2 = cross(l43, l31) * cross(l43, l32);
    //cout << r1 << " " << r2 << "\n";
    //cout << r1 << " " << r2 << " ";
    if (r1 == 0 && r2 == 0)
    {
        return (check(min(x1, x2), max(x1, x2), min(x3, x4), max(x3, x4)) && 
            check(min(y1, y2), max(y1, y2), min(y3, y4), max(y3, y4)));
    }
    return r1 <= 0 && r2 <= 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << (solve() ? 1 : 0);
    return 0;
}
 