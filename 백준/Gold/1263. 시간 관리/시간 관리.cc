#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;
int N;
struct Node {
    int s, e;
    int t;
    bool operator<(Node o) const {
        if (e > o.e) return true;
        else if (e < o.e) return false;
        return t > o.t;
    }
};
vector<Node> v;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({ b - a, b, a });
        // 끝나는시간이 가장늦은애들부터..
    }
    sort(v.begin(), v.end());
    int prev = 2000000000;
    for (Node now : v)
    {
        //cout << now.e << "\n";
        if (now.e < prev)
        {
            prev = now.e - now.t;
        }
        else
        {
            prev -= now.t;
        }
    }
    cout << (prev < 0 ? -1 : prev);
    return 0;

}