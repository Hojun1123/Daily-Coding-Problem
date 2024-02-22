#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
struct yx {
    float y, x;
};
yx stars[100];
struct Node {
    int a, b;
    float c;
    bool operator<(Node o) const {
        return c < o.c;
    }
};
vector<Node> v;
int N;
int arr[100];
void init()
{
    for (int i = 0; i < N; ++i)
    {
        arr[i] = i;
    }
}
int Find(int curr)
{
    if (curr == arr[curr])return curr;
    int ret = Find(arr[curr]);
    arr[curr] = ret;
    return ret;
}
void Union(int a, int b)
{
    int r1 = Find(a);
    int r2 = Find(b);
    if (r1 == r2) return;
    arr[r2] = r1;
}
int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    //n개의 별을 이어서 별자리를 만듬
    //최소비용을 ㅜ해야함
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> stars[i].y >> stars[i].x;
    }
    for (int i = 0; i < N - 1; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            v.push_back({i, j, sqrt((stars[i].y - stars[j].y) * (stars[i].y - stars[j].y) +
                (stars[i].x - stars[j].x) * (stars[i].x - stars[j].x)) });
        }
    }
    sort(v.begin(), v.end());
    init();
    int sCount = 0;
    float result = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        int a = v[i].a;
        int b = v[i].b;
        if (Find(a) == Find(b)) continue;
        Union(a, b);
        sCount++;
        result += v[i].c;
        if (sCount == N - 1)break;
    }
    cout << result;
    return 0;
}