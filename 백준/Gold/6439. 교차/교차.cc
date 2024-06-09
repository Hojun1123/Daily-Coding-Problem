#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_map>
using namespace std;
struct Dot {
    int x, y;
};
Dot line1;
Dot line2;
int cross(Dot a, Dot b, Dot c)
{
    // a > b > c
    Dot l1 = { b.x - a.x, b.y - a.y };
    Dot l2 = { c.x - b.x, c.y - b.y };
    int r = l1.x* l2.y - l1.y * l2.x;
    if (r < 0) return -1;
    else if (r > 0) return 1;
    return 0;
}
void solve()
{
    Dot lt, rb, lb, rt;
    int a, b, c, d;
    cin >> line1.x >> line1.y >> line2.x >> line2.y;
    cin >> a >> b >> c >> d;
    lt = { min(a, c), max(b, d) };
    lb = { min(a, c), min(b, d) };
    rt = { max(a, c), max(b, d) };
    rb = { max(a, c), min(b, d) };
    
    int answer = 0;
    if (min(a, c) <= line1.x && line1.x <= max(a, c) && min(b, d) <= line1.y && line1.y <= max(b, d)) answer = 1;
    else if (min(a, c) <= line2.x && line2.x <= max(a, c) && min(b, d) <= line2.y && line2.y <= max(b, d)) answer = 1;
    // lt, rt, rb, lb
    // lt-rt와 line이 교차하는지
    int r1 = cross(lt, rt, line1) * cross(lt, rt, line2);
    int r2 = cross(line1, line2, lt) * cross(line1, line2, rt);
    if (r1 == 0 && r2 == 0) {
        if (line1.y == line2.y) {
            if ((lt.x <= line1.x && line1.x <= rt.x) || (lt.x <= line2.x && line2.x <= rt.x)) {
                answer = 1;
            }
        }
    }
    else if (r1 <= 0 && r2 <= 0) answer = 1;

    r1 = cross(rt, rb, line1) * cross(rt, rb, line2);
    r2 = cross(line1, line2, rt) * cross(line1, line2, rb);
    if (r1 == 0 && r2 == 0) {
        if (line1.x == line2.x) {
            if ((rb.y <= line1.y && line1.y <= rt.y) || (rb.y <= line2.y && line2.y <= rt.y)) {
                answer = 1;
            }
        }
    }
    else if (r1 <= 0 && r2 <= 0) answer = 1;

    r1 = cross(lb, rb, line1) * cross(lb, rb, line2);
    r2 = cross(line1, line2, lb) * cross(line1, line2, rb);
    if (r1 == 0 && r2 == 0) {
        if (line1.y == line2.y) {
            if ((lb.x <= line1.x && line1.x <= rb.x) || (lb.x <= line2.x && line2.x <= rb.x)) {
                answer = 1;
            }
        }
    }
    else if (r1 <= 0 && r2 <= 0) answer = 1;

    // lt와 line이 교차하는지
    r1 = cross(lb, lt, line1) * cross(lb, lt, line2);
    r2 = cross(line1, line2, lb) * cross(line1, line2, lt);
    if (r1 == 0 && r2 == 0) {
        if (line1.x == line2.x) {
            if ((lb.y <= line1.y && line1.y <= lt.y) || (lb.y <= line2.y && line2.y <= lt.y)) {
                answer = 1;
            }
        }
    }
    else if (r1 <= 0 && r2 <= 0) answer = 1;

    cout << (answer ? "T\n" : "F\n");
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) solve();
    return 0;
 }