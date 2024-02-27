#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;
struct line {
    int x;
    int dir;    //1은 아래서 위, 0은 위에서 아래
    bool operator<(line o) const
    {
        return x < o.x;
    }
};
int N;
deque<line> v;
stack<int> s;
struct Node {
    int s, e;
    Node(int a, int b)
    {
        if (a > b)
        {
            s = b;
            e = a;
        }
        else
        {
            s = a;
            e = b;
        }
    }
    bool operator<(Node o) const {
        if (s < o.s) return true;
        else if (s > o.s) return false;
        if (e < o.e) return true;
        else if (e > o.e) return false;
        return false;
    }
};
vector<Node> result;
int answer[100000];
int check[100000];
int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin >> N;
    int y, x;
    int py, px;
    int sy, sx;
    cin >> px >> py;
    sy = py; 
    sx = px;
    for (int i = 1; i < N; ++i)
    {
        cin >> x >> y;
        if (px == x && py * y <= 0)
        {
            if (py < y)
            {
                v.push_back({ x, 1 });
            }
            else
            {
                v.push_back({ x, 0 });
            }
        }
        px = x;
        py = y;
    }
    if (sx == x)
    {
        if (sy < py * y <= 0)
        {
            v.push_front({ x, 1 });
        }
        else
        {
            v.push_front({ x, 0 });
        }
    }
    //sort(v.begin(), v.end());
    //다른 봉우리에 의해 포함되지 않는 봉우리 개수, 다른 봉우리를 포함하지 않는 봉우리 개수
    //for (auto i : v) cout << i.x << " " << i.dir << "\n";

    line prev = v[v.size() - 1];
    for (int i = 0; i < v.size(); ++i)
    {
        line now = v[i];
        if (prev.dir && now.dir == 0)
        {
            result.push_back(Node(prev.x, now.x));
        }
        prev = v[i];
    }

    sort(result.begin(), result.end());
    //for (auto i : result)   cout << i.s << " " << i.e << "\n";
    int out = 0;   //다른 봉우리에 포함되지 않는
    int inside = 0; //다른 봉우리를 포함하지 않는

    int ps = -2000000000, pe = -2000000000;
    for (int i = 0; i < result.size(); ++i)
    {
        if (pe < result[i].s)
        {
            out++;
            pe = result[i].e;
        }
        if (i + 1 < result.size() && result[i].e < result[i + 1].s)
        {
            inside++;
        }
    }
    cout << out << " " << inside + 1;
    return 0;
}