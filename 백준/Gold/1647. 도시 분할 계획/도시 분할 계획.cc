#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int N, M;
struct Node {
    int a, b, cost;
    bool operator < (Node o) const {
        return cost < o.cost;
    }
};
vector<Node> v;
int arr[100001];
void init()
{
    for (int i = 1; i <= N; ++i)
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
    //N개의 집과 M개의 길, 마을을 두개로 분할
    //마을은 집이 하나 있어야 함
    // N - 2 개의 경로를 뽑음 됨
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({ a, b, c });
    }

    init();
    sort(v.begin(), v.end());
    int r = 0;
    int sc = 0;
    for (Node i : v)
    {
        if (sc >= N - 2)
        {
            break;
        }
        int a = i.a;
        int b = i.b;
        if (Find(a) == Find(b)) continue;
        Union(a, b);
        sc++;
        r += i.cost;
    }
    cout << r;
    return 0;
}