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
#include <sstream>
using namespace std;
struct xy {
    long long x, y;
};
int N;
struct Line{
    xy A, B;
    long long w;
    bool operator<(Line o) const {
        return w < o.w;
    }
};
int ccw(xy a, xy b, xy c)
{
    xy l1 = { b.x - a.x, b.y - a.y };
    xy l2 = { c.x - b.x, c.y - b.y };
    long long r = l1.x * l2.y - l1.y * l2.x;
    if (r > 0) return 1;
    else if (r < 0) return -1;
    return 0;
}
long long ans = 0;
vector<Line> v;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        v.push_back({ {a, b}, {c, d}, e });
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < N - 1; ++i)
    {
        int cnt = 1;
        for (int j = i + 1; j < N; ++j)
        {
            int r1 = ccw(v[i].A, v[i].B, v[j].A) *
                ccw(v[i].A, v[i].B, v[j].B);
            int r2 = ccw(v[j].A, v[j].B, v[i].A) *
                ccw(v[j].A, v[j].B, v[i].B);
            if (r1 <= 0 && r2 <= 0) cnt++;
        }
        ans += v[i].w * cnt;
    }
    cout << ans + v[N - 1].w;
    return 0;
}