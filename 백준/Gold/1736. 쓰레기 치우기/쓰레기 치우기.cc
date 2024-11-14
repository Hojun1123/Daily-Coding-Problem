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
int check[100][100];
int cnt = 0;
void bt(int y, int x) {
    if (cnt == 0) return;
    for (int i = y; i < N; ++i) {
        for (int j = x; j < M; ++j) {
            if (check[i][j] == 0) continue;
            check[i][j] = 0;
            cnt--;
            bt(i, j);
            return;
        }
    }
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> check[i][j];
            if (check[i][j]) cnt++;
        }
    }
    int ans;
    if (check[0][0]) {
        ans = 1;
        check[0][0] = 0;
        bt(0, 0);
        cnt--;
    }
    else {
        ans = 0;
    }
    while (cnt > 0) {
        bt(0, 0);
        ans++;
    }
    cout << ans;
    return 0;
}