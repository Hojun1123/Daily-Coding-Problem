#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <stack>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;
int N, M;
int arr[3003];
int cnt[3003];
int Find(int n) {
    if (n == arr[n]) return n;
    int ret = Find(arr[n]);
    arr[n] = ret;
    return ret;
}
void Union(int a, int b)
{
    int r1 = Find(a);
    int r2 = Find(b);
    if (r1 == r2) return;
    if (r1 < r2) arr[r2] = r1;
    else arr[r1] = r2;
}
int main()
{
    // 노드가 전부 연결, 차수가 홀수인 노드가 0 or 2 개
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) arr[i] = i;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        cnt[a]++;
        cnt[b]++;
        Union(a, b);
    }
    int rc = 0;
    for (int i = 1; i <= N; ++i) {
        if (cnt[i] % 2 == 1) rc++;
    }
    int lc = 1;
    
    for (int i = 2; i <= N; ++i) {
        if (Find(arr[i]) == 1) continue;
        lc = 0;
        break;
    }
    if ((rc == 0 || rc == 2) && lc) {
        cout << "YES";
    }
    else cout << "NO";
    return 0;
}