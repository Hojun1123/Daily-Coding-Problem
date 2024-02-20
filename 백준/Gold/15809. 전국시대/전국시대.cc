#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int N, M;
int country[100001];
int people[100001];
int s[100001];
map<int, int> m;
void init()
{
    for (int i = 1; i <= N; ++i)
    {
        country[i] = i;
    }
}
int Find(int a)
{
    if (a == country[a]) return a;
    int ret = Find(country[a]);
    country[a] = ret;
    return ret;
}
void Union(int a, int b)
{
    int r1 = Find(a);
    int r2 = Find(b);
    if (r1 == r2) return;
    country[r2] = r1;
    s[r1] += s[r2];
}
int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin >> N >> M;  //국가의 수, 기록의 수
    for (int i = 1; i <= N; ++i)
    {
        cin >> s[i];
    }
    init();
    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            //동맹
            Union(b, c);
        }
        else
        {
            //전쟁
            int bb = Find(b);
            int cc = Find(c);
            if (s[bb] > s[cc])
            {
                s[bb] = s[bb] - s[cc];
                s[cc] = 0;
                Union(bb, cc);
            }
            else if (s[cc] > s[bb])
            {
                s[cc] = s[cc] - s[bb];
                s[bb] = 0;
                Union(cc, bb);
            }
            else
            {
                s[bb] = 0;
                s[cc] = 0;
            }
        }
    }
    
    for (int i = 1; i <= N; ++i)
    {
        int tmp = Find(i);
        if (s[tmp] > 0)
            m[tmp] = 1;
    }
    cout << m.size() << "\n";
    vector<int> v;
    for (auto i : m)
    {
        v.push_back(s[i.first]);
    }
    sort(v.begin(), v.end());
    for (int i : v)
        cout << i << " ";
    return 0;
}