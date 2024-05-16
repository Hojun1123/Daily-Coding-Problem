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
    int x, y;
};
xy arr[4];
int cross(xy a, xy b)
{
    int r = (a.x * b.y - a.y * b.x);
    if (r == 0) return 0;
    else if (r > 0) return 1;
    else return  -1;
}
bool solve()
{
    for (int i = 0; i < 4; ++i) cin >> arr[i].x >> arr[i].y;
    xy ab = { arr[1].x - arr[0].x, arr[1].y - arr[0].y };
    xy bc = { arr[2].x - arr[1].x, arr[2].y - arr[1].y };
    xy bd = { arr[3].x - arr[1].x, arr[3].y - arr[1].y };
    int r1 = cross(ab, bc) * cross(ab, bd);

    xy cd = { arr[3].x - arr[2].x, arr[3].y - arr[2].y };
    xy da = { arr[0].x - arr[3].x, arr[0].y - arr[3].y };
    xy db = { arr[1].x - arr[3].x, arr[1].y - arr[3].y };
    int r2 = cross(cd, da) * cross(cd, db);
    //cout << r1 << " " << r2;
    return r1 < 0 && r2 < 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << (solve() ? 1 : 0);
    return 0;
}
