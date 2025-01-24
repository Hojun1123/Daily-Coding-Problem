#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
using namespace std;
struct Dot {
    int x, y;
    bool operator<(const Dot& o) const {
        if (x < o.x) return true;
        else if (x > o.x) return false;
        return y < o.y;
    }
};
vector<Dot> v;
int N, T;
vector<Dot> answer;
map<Dot, int> indexMap;
int cross(Dot a, Dot b, Dot c)
{
    // a > b > c
    Dot l1 = { b.x - a.x, b.y - a.y };
    Dot l2 = { c.x - b.x, c.y - b.y };
    int r = l1.x * l2.y - l1.y * l2.x;
    if (r < 0) return -1;
    else if (r > 0) return 1;
    return 0;
}
int getDistance(Dot a)
{
    return (v[0].x - a.x) * (v[0].x - a.x) + (v[0].y - a.y) * (v[0].y - a.y);
}
bool cmp(Dot a, Dot b) {
    int r = cross(v[0], a, b);
    if (r > 0) return 1;
    else if (r == 0) return getDistance(a) < getDistance(b);
    return 0;
}
void solve()
{
    v.clear();
    indexMap.clear();
    answer.clear();
    cin >> N;
    int a, b, ta, tb;
    cin >> a >> b;
    v.push_back({ a, b });
    for (int i = 1; i < N; ++i) {
        //dot save
        //가장 x,y가 작은 시작 점 찾기
        cin >> a >> b;
        indexMap[{a, b}] = i;
        if (a < v[0].x) {
            ta = v[0].x;
            tb = v[0].y;
            v[0] = { a, b };
            v.push_back({ ta, tb });
        }
        else if (a == v[0].x && b < v[0].y) {
            ta = v[0].x;
            tb = v[0].y;
            v[0] = { a, b };
            v.push_back({ ta, tb });
        }
        else {
            v.push_back({ a, b });
        }
    }

    // 반시계 정렬
    sort(v.begin() + 1, v.end(), cmp);
    answer.push_back(v[0]);
    answer.push_back(v[1]);
    int rflag = 0;
    for (int i = 2; i < v.size() - 1; ++i) {
        if (cross(v[0], v[v.size() - 1], v[i]) == 0) {
            for (int j = v.size() - 1; j >= i; --j) {
                answer.push_back(v[j]);
            }
            rflag = 1;
            break;
        }
        answer.push_back(v[i]);
    }
    if (rflag == 0) answer.push_back(v[v.size() - 1]);
    for (int i = 0; i < answer.size(); ++i) {
        cout << indexMap[answer[i]] << " ";
    }
    cout << "\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    for (int i = 0; i < T; ++i) solve();
    return 0;
}