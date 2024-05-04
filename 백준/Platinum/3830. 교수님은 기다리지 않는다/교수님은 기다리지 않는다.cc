#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <cmath>
#include <unordered_map>
#include <cstring>
#include <algorithm>
using namespace std;
//두 샘플을 고름 -> 무게 차이 -> 가끔 교수님이 와서 물어봄 -> 대답가능/불가능
//! a b w -> b가 a보다 w그램 무거움, -> 두 샘플이 연결되어있다면 무게 비교가 가능.
//? a b 
int N, M;
int arr[100001];    //유니온 파인드
int result[100001]; //루트
void init() {
    for (int i = 1; i <= N; ++i) {
        result[i] = 0;  //처음 diff = 0
        arr[i] = i;
    }
}
int Find(int n) {
    if (n == arr[n]) return n;
    int ret = Find(arr[n]);
    result[n] += result[arr[n]];
    arr[n] = ret;
    return ret;
}
void Union(int a, int b, int w) {
    int r1 = Find(a);
    int r2 = Find(b);
    if (r1 == r2) return;
    arr[r2] = r1;
    result[r2] = result[a] - result[b] + w;
}
void solve()
{
    init();

    char op;
    int a, b, c;
    stack<int> s;
    for (int i = 0; i < M; ++i) {
        cin >> op;
        if (op == '!') {
            // 배열 업데이트
            cin >> a >> b >> c;
            if (a > b) {
                swap(a, b);
                c *= -1;
            }
            Union(a, b, c);
        }
        else {
            cin >> a >> b;
            if (Find(a) == Find(b)) cout << result[b] - result[a] << "\n";
            else cout << "UNKNOWN\n";
        }
    }
    //cout << "\n\n";
    //for (int i = 1; i <= N; ++i) cout << result[i] << " ";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (1) {
        cin >> N >> M;
        solve();
        if (N || M) continue;
        break;
    }
    return 0;
}