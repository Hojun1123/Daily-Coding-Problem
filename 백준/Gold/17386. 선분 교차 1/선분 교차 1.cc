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
long long cross(xy a, xy b, xy c)
{
    xy l1 = { b.x - a.x, b.y - a.y };
    xy l2 = { c.x - b.x, c.y - b.y };
    long long r = l1.x * l2.y - l1.y * l2.x;
    if (r < 0) return -1;
    else if (r > 0) return 1;
    return 0;
}
int solve()
{
    xy a, b, c, d;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;
    cin >> d.x >> d.y;
    long long c1 = cross(a, b, c);
    long long c2 = cross(a, b, d);

    long long c3 = cross(c, d, a);
    long long c4 = cross(c, d, b);

    if (c1 * c2 <= 0 && c3 * c4 <= 0) return 1;
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << (solve() ? 1 : 0);
    return 0;
}
 