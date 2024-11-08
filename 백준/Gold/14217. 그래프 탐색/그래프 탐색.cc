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
#include <regex>
using namespace std;
int N, M;
int graph[501][501];
int check[501];
queue<int> q;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            graph[b][c] = 1;
            graph[c][b] = 1;
        }
        else {
            graph[b][c] = 0;
            graph[c][b] = 0;

        }

        memset(check, 0, sizeof(check));
        check[1] = 1;
        q.push(1);
        int cnt = 1;
        while (!q.empty()) {
            int qs = q.size();
            for (int k = 0; k < qs; ++k) {
                int now = q.front();
                q.pop();
                for (int j = 1; j <= N; ++j) {
                    if (graph[now][j] && check[j] == 0) {
                        check[j] = cnt;
                        q.push(j);
                    }
                }
            }
            cnt++;
        }
        cout << 0 << " ";
        for (int k = 2; k <= N; ++k) {
            cout << (check[k] ? check[k] : -1) << " ";
        }
        cout << "\n";
    }

    
    return 0;
}