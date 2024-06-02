#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
int N, M;
struct Node {
    int p1, p2;
    long double distance;
    bool operator<(Node o) const {
        return distance < o.distance;
    }
};
struct Point {
    long double x, y;
};
Point point[1000];
int uf[1000];
vector<Node> v;
void init() {
    for (int i = 0; i < N; ++i) {
        uf[i] = i;
    }
}
int Find(int n) {
    if (n == uf[n]) return n;
    int r = Find(uf[n]);
    uf[n] = r;
    return r;
}
void Union(int a, int b) {
    int r1 = Find(a);
    int r2 = Find(b);
    if (r1 == r2) return;
    uf[r2] = r1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> point[i].x >> point[i].y;
    }
    init();
    int scnt = M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        if (Find(a - 1) == Find(b - 1)) {
            scnt--;
            continue;
        }
        if (a < b)
            Union(a - 1, b - 1);
        else
            Union(b - 1, a - 1);
    }
    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            long long xx = pow(point[i].x - point[j].x, 2);
            long long yy = pow(point[i].y - point[j].y, 2);
            long double distance = sqrt(xx + yy);
            v.push_back({ i, j, (long double)distance });
        }
    }
    sort(v.begin(), v.end());
    long double ans = 0.0;
    for (int i = 0; i < v.size(); ++i) {
        int a = v[i].p1;
        int b = v[i].p2;
        if (Find(a) == Find(b)) continue;
        Union(a, b);
        scnt++;
        ans += v[i].distance;
        if (scnt >= N - 1) {
            break;
        }
    }
    cout.precision(2);
    cout << fixed;
    cout << ans;
    return 0;
 }