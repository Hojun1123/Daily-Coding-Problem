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
int N, M;
struct Node {
    int a, b, id;
    bool operator<(Node o) const {
        return a < o.a;
    }
};
vector<Node> spicy;
vector<Node> sweet;
int bs1(int left, int right, vector<Node> &v, int a)
{
    int mid;
    int m = -1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (v[mid].a >= a)
        {
            m = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return m;
}
int bs2(int left, int right, vector<Node>& v, int a)
{
    int mid;
    int m = -1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (v[mid].a <= a)
        {
            m = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return m;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        int a, b;
        cin >> a >> b;
        spicy.push_back({a, b, i});    //spicy
        sweet.push_back({b, a, i});    //sweet
    }
    sort(spicy.begin(), spicy.end());
    sort(sweet.begin(), sweet.end());
    int check[100000];
    for (int i = 0; i < M; ++i)
    {
        memset(check, 0, sizeof(int) * N);
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        int uu = bs1(0, N - 1, spicy, u);
        int vv = bs2(0, N - 1, spicy, v);
        int xx = bs1(0, N - 1, sweet, x);
        int yy = bs2(0, N - 1, sweet, y);
        if (uu != -1 && vv != -1)
        {
            for (int j = uu; j <= vv; ++j)
            {
                check[spicy[j].id]++;
            }
        }
        if (xx != -1 && yy != -1)
        {
            for (int j = xx; j <= yy; ++j)
            {
                check[sweet[j].id]++;
            }
        }
        int cnt = 0;
        for (int i = 0; i < N; ++i)
        {
            if (check[i] == 2) cnt++;
        }
        cout << cnt << "\n";
    }
    return 0;
}