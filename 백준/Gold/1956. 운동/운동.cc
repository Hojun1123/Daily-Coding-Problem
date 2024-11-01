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
int answer[401][401];
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            answer[i][j] = 1000000000;
        }
    }
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        answer[a][b] = c;
    }

    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                answer[i][j] = min(answer[i][j], answer[i][k] + answer[k][j]);
            }
        }
    }
    int r = 2100000000;
    for (int i = 1; i <= N; ++i) {
        //cout << answer[i][i] << " ";
        r = min(r, answer[i][i]);
    }
    cout << (r > 999999999 ?-1 : r);
    return 0;
}