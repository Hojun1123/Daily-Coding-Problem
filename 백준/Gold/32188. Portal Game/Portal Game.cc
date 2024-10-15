#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
int N, C;
//포탈이 C개, 레드 포탈과 블루 포탈 두개가 있음
// 각 칸에는 포탈 시작 지점이 1개 존재
//시작지점이  a - b칸으로 이동
//
struct Node {
    int n, c;
    bool operator<(Node o) const {
        return c > o.c;
    }
};
int ans[100000];
unordered_map<int, Node> portal;
int isPortal[100000];
priority_queue<Node> pq;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> C;
    for (int i = 0; i < C; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        isPortal[b] = 1;
        if (a) {
            //블루포탈
            portal[b] = { 1, c };
        }
        else {
            //레드포탈
            portal[b] = { 0, c };
        }
    }
    for (int i = 0; i < N; ++i) ans[i] = 987654321;
    pq.push({ 0, 0 });
    ans[0] = 0;
    while (!pq.empty()) {
        Node now = pq.top();
        pq.pop();
        if (isPortal[now.n]) {
            Node p = portal[now.n];
            if (p.n) {
                //블루
                int nxtCost = ans[now.n] + 1;
                if (nxtCost < ans[now.n + 1]) {
                    pq.push({ now.n + 1, nxtCost });
                    ans[now.n + 1] = nxtCost;
                }
                if (now.c < ans[p.c]) {
                    pq.push({ p.c, now.c });
                    ans[p.c] = now.c;
                }
            }
            else {
                //레드
                if (now.c < ans[p.c]) {
                    pq.push({ p.c, now.c });
                    ans[p.c] = now.c;
                }
            }
        }
        else {
            int nxtCost = ans[now.n] + 1;
            if (nxtCost < ans[now.n + 1]) {
                pq.push({ now.n + 1, nxtCost });
                ans[now.n + 1] = nxtCost;
            }
        }
    }
    cout << (ans[N - 1] < 987654300 ? ans[N - 1] : -1);
    return 0;
}