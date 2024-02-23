#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <vector>
#include <sstream>
using namespace std;
int N, M;
struct Node{
    int a, b,c;
    bool operator<(Node o) const {
        return c < o.c;
    }
};
vector<Node> v;
int arr[100001];
void init()
{
    for(int i = 1; i<= N; ++i){
        arr[i] = i;
    }
}
int Find(int a)
{
    if(arr[a] == a) return a;
    int ret = Find(arr[a]);
    arr[a] = ret;
    return ret;
}
void Union(int a, int b){
    int r1 = Find(a);
    int r2 = Find(b);
    if(r1 == r2) return;
    arr[r2] = r1;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    long long o = 0;
    for(int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({a, b, c});
        o+= c;
    }
    sort(v.begin(), v.end());
    init();
    int sc=0;
    long long s=0;
    for(Node i : v){
        int a = i.a;
        int b = i.b;
        if(Find(a) == Find(b)) continue;
        Union(a,b);
        sc++;
        s+= i.c;
        if(sc == N - 1) break;
    }
    cout << (sc == N-1 ? o - s : -1);
    return 0;
}