#include <iostream>
#include <vector>
#include <map>
#include <deque>
#include <list>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <cstring>
#include <list>
using namespace std;
int N, K, C;
struct product {
    int m;
    int v;
    bool operator<(product o) const {
        return v > o.v;
    }
};
bool cmp(product a, product b)
{
    if (a.m < b.m) return true;
    else if (a.m > b.m) return false;
    return a.v > b.v;
}
vector<product> v;
vector<int> bag;
priority_queue<int> pq;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K ;
    for (int i = 0; i < N; ++i)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({ a, b });
    }
    for (int i = 0; i < K; ++i)
    {
        int a;
        cin >> a;
        bag.push_back(a);
    }
    sort(bag.begin(), bag.end());
    sort(v.begin(), v.end(), cmp);

    long long r = 0;
    int index = 0;
    for (int i = 0; i < K; ++i)
    {
        while (index < N && v[index].m <= bag[i])
        {
            pq.push(v[index++].v);
        }
        if (pq.empty()) continue;
        r += pq.top();
        pq.pop();
    }
    cout << r;
    return 0;
}
