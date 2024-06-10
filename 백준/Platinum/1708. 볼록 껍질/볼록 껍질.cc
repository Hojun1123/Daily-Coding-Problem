#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;
struct Dot {
    long long x, y;
};
vector<Dot> v;
int N;
stack<Dot> answer;
int cross(Dot a, Dot b, Dot c)
{
    // a > b > c
    Dot l1 = { b.x - a.x, b.y - a.y };
    Dot l2 = { c.x - b.x, c.y - b.y };
    long long r = l1.x * l2.y - l1.y * l2.x;
    if (r < 0) return -1;
    else if (r > 0) return 1;
    return 0;
}
long long getDistance(Dot a)
{
    return (v[0].x - a.x) * (v[0].x - a.x) + (v[0].y - a.y) * (v[0].y - a.y);
}
bool cmp(Dot a, Dot b) {
    int r = cross(v[0], a, b);
    if (r > 0) return 1;
    else if (r == 0) return getDistance(a) < getDistance(b);
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    int a, b, tmp1, tmp2;
    cin >> a >> b;
    v.push_back({ a, b });
    for (int i = 1; i < N; ++i) {
        cin >> a >> b;
        if (a < v[0].x) {
            tmp1 = v[0].x;
            tmp2 = v[0].y;
            v[0] = { a, b };
            v.push_back({ tmp1, tmp2 });
        }
        else if (a == v[0].x && b < v[0].y) {
            tmp1 = v[0].x;
            tmp2 = v[0].y;
            v[0] = { a, b };
            v.push_back({ tmp1, tmp2 });
        }
        else {
            v.push_back({ a, b });
        }
    }
    sort(v.begin() + 1, v.end(), cmp);
    //for (Dot i : v) cout << i.x << " " << i.y << "\n";
    answer.push(v[0]);
    answer.push(v[1]);
    for (int i = 2; i < N; ++i)
    {
        while (answer.size() >= 2) {
            Dot prev = answer.top();
            answer.pop();
            Dot prev2 = answer.top();
            if (cross(prev2, prev, v[i]) > 0) {
                answer.push(prev);
                break;
            }
        }
        answer.push(v[i]);
    }
    cout << answer.size();
    return 0;
 }