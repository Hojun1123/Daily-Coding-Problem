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
int N, M;
struct line {
    int a, b;
};
vector<line> v;
int arr[500000];
void init() {
    for (int i = 0; i < N; ++i) {
        arr[i] = i;
    }
}
int Find(int curr) {
    if (curr == arr[curr]) return curr;
    int ret = Find(arr[curr]);
    arr[curr] = ret;
    return ret;
}
void Union(int a, int b) {
    int r1 = Find(a); int r2 = Find(b);
    if (r1 == r2) return;
    arr[r2] = r1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        if (a < b)
        {
            v.push_back({ a, b });
        }
        else {
            v.push_back({ b, a });
        }
    }
    init();
    int cnt = 1;
    int ef = false;
    for (line nPick : v)
    {
        int a = nPick.a;
        int b = nPick.b;
        if (Find(a) == Find(b)){
            ef = true;
            break;
        }
        Union(a, b);
        cnt++;
    }
    cout << (ef ? cnt : 0);
    return 0;
}
