#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
using namespace std;
int check[1000][1000];
int input[1000][5];
int ans[1000];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> input[i][j];
        }
    }
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < N - 1; ++j) {
            for (int k = j + 1; k < N; ++k) {
                if (input[j][i] == input[k][i]) {
                    check[j][k] = 1;
                    check[k][j] = 1;
                }
            }
        }
    }

    int ans = 0;
    int index = 0;
    for (int i = 0; i < N; ++i) {
        int cnt = 0;
        for (int j = 0; j < N; ++j) {
            if (check[i][j]) cnt++;
        }
        if (ans < cnt) {
            index = i;
            ans = cnt;
        }
    }
    cout << index + 1;
    return 0;
}