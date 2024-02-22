#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>
#include <deque>
#include <deque>
#include <map>
#include <vector>
#include <sstream>
using namespace std;
int m, n; //집의 수, 길의 수
struct Node {
    int x, y, z;
    bool operator<(Node o) const {
        return z < o.z;
    }
};
vector<Node> v;
int arr[200000];
void init()
{
    for (int i = 0; i < m; ++i) arr[i] = i;
}
int Find(int curr)
{
    if (curr == arr[curr]) return curr;
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
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    while (true)
    {
        cin >> m >> n;
        if (m == 0 && n == 0) break;
        v = vector<Node>();
        int s = 0;
        for (int i = 0; i < n; ++i)
        {
            int a, b, c;
            cin >> a >> b >> c;
            v.push_back({ a, b, c });
            s += c;
        }
        init();
        sort(v.begin(), v.end());
        int sc = 0;
        int result = 0;
        for (auto i : v)
        {
            int a = i.x;
            int b = i.y;
            if (Find(a) == Find(b))continue;
            Union(a, b);
            result += i.z;
            sc++;
            if (sc == m - 1)break;
        }
        cout << s - result << "\n";
    }
    return 0;
}