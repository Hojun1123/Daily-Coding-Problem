#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
using namespace std;
int N, M, T;
// 가입 ㅎ ㅜ 아는 사람을 친구로 추가함
//친구 관계 그래프르ㅜㄹ 그림
// 유저수와 친구관계가 입력으로 주어짐
int arr[1000000];
int Find(int n) {
    if (arr[n] == n) return n;
    int ret = Find(arr[n]);
    arr[n] = ret;
    return ret;
}
void Union(int a, int b) {
    int r1 = Find(a);
    int r2 = Find(b);
    if (r1 == r2) return;
    if (r1 < r2) {
        arr[r2] = r1;
    }
    else arr[r1] = r2;
}
void solve(int tt) {
    cin >> N;
    for (int i = 0; i < N; ++i) arr[i] = i;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        Union(a, b);
    }
    cin >> M;
    cout << "Scenario " << tt << ":\n";
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        cout << (Find(a) == Find(b)) << "\n";
    }
    cout << "\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //유저수
    cin >> T; for(int i = 0; i < T; ++i) solve(i + 1);
    return 0;
}