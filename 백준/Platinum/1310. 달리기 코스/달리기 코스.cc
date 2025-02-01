#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;
struct Dot {
    long long x, y;
};
int N;
vector<Dot> input;
int cross(Dot& a, Dot& b, Dot& c) {
    Dot line1 = { b.x - a.x, b.y - a.y };
    Dot line2 = { c.x - b.x, c.y - b.y };
    long long r = line1.x * line2.y - line1.y * line2.x;
    if (r < 0) return -1;
    if (r > 0) return 1;
    return 0;
}
int cross2(Dot& a, Dot& b, Dot& c, Dot& d) {
    Dot line1 = { b.x - a.x, b.y - a.y };
    Dot line2 = { d.x - c.x, d.y - c.y };
    long long r = line1.x * line2.y - line1.y * line2.x;
    if (r < 0) return -1;
    if (r > 0) return 1;
    return 0;
}
long long getDistance(Dot a) {
    return (input[0].x - a.x) * (input[0].x - a.x) + (input[0].y - a.y) * (input[0].y - a.y);
}
bool cmp(Dot& a, Dot& b) {
    int r = cross(input[0], a, b);
    if (r > 0) return 1;
    if (r == 0) return getDistance(a) < getDistance(b);
    return 0;
}
stack<Dot> s;
vector<Dot> convexHull;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    long long tx, ty, ttx, tty;
    cin >> tx >> ty ;
    input.push_back({ tx, ty });
    for (int i = 1; i < N; ++i) {
        cin >> tx >> ty;
        if (tx < input[0].x) {
            ttx = input[0].x;
            tty = input[0].y;
            input[0] = { tx, ty };
            input.push_back({ ttx, tty });
        }
        else if (tx == input[0].x && ty < input[0].y) {
            ttx = input[0].x;
            tty = input[0].y;
            input[0] = { tx, ty };
            input.push_back({ ttx, tty });
        }
        else {
            input.push_back({ tx,ty });
        }
    }
    sort(input.begin() + 1, input.end(), cmp);
    s.push(input[0]);
    s.push(input[1]);
    for (int i = 2; i < input.size(); ++i) {
        while (s.size() >= 2) {
            Dot prev = s.top();
            s.pop();
            Dot pprev = s.top();
            if (cross(pprev, prev, input[i]) > 0) {
                s.push(prev);
                break;
            }
        }
        s.push(input[i]);
    }
    while (!s.empty()) {
        convexHull.push_back(s.top());
        s.pop();
    }
    long long maxDis = 0;
    int index = 1;
    int cs = convexHull.size();
    for (int i = 0; i < cs; ++i) {
        while (cross2(convexHull[i], convexHull[(i + 1) % cs], convexHull[index % cs], convexHull[(index + 1) % cs]) < 0) {
            long long currDis = (convexHull[i].x - convexHull[index % cs].x) * (convexHull[i].x - convexHull[index % cs].x) + (convexHull[i].y - convexHull[index % cs].y) * (convexHull[i].y - convexHull[index % cs].y);
            maxDis = max(maxDis, currDis);
            index++;
        }
        long long currDis = (convexHull[i].x - convexHull[index % cs].x) * (convexHull[i].x - convexHull[index % cs].x) + (convexHull[i].y - convexHull[index % cs].y) * (convexHull[i].y - convexHull[index % cs].y);
        maxDis = max(maxDis, currDis);
    }
    cout << maxDis;
    return 0;
}