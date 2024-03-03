#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
int N, Q;
int answer[100000];
struct Line {
    int n;
    int x1, x2;
    int y;
    bool operator<(Line o) const {
        return x1 < o.x1;
    }
};
vector<Line> v;
map<int, int> hashMap;
void init()
{
    for (int i = 0; i < N; ++i)
    {
        answer[i] = i;
    }
}
int Find(int curr)
{
    if (curr == answer[curr]) return curr;
    int ret = Find(answer[curr]);
    answer[curr] = ret;
    return ret;
}
void Union(int a, int b)
{
    int r1 = Find(a);
    int r2 = Find(b);
    if (r1 == r2) return;
    answer[r2] = r1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> Q;
    for (int i = 0; i < N; ++i)
    {
        int x1, x2, y;
        cin >> x1 >> x2 >> y;
        v.push_back({ i, x1, x2, y });
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < N; ++i)
    {
        hashMap[v[i].n] = i;
    }
    init();
    Line prev = v[0];
    int maxLength = v[0].x2;
    for (int i = 1; i < N; ++i)
    {
        Line now = v[i];
        if (maxLength >= now.x1)
        {
            Union(i - 1, i);
            if (maxLength < now.x2)
            {
                maxLength = now.x2;
            }
        }
        else
        {
            maxLength = now.x2;
        }
        prev = now;
    }

    for (int i = 0; i < Q; ++i)
    {
        int a, b;
        cin >> a >> b;
        cout << (Find(hashMap[a - 1]) == Find(hashMap[b - 1]) ? 1 : 0) << "\n";
    }
    return 0;
}