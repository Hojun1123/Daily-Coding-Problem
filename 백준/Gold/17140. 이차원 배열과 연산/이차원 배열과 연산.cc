#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <string>
using namespace std;
int R, C, K;
int board[101][101];
struct Num{
    int n, cnt;
    bool operator<(Num o) const {
        if (cnt < o.cnt) return true;
        else if (cnt > o.cnt) return false;
        return n < o.n;
    }
};
//R 연산: 행의 개수 >= 열의 개수
//C 연산: 열의 개수 > 행의 개수
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> R >> C >> K;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> board[i][j];
        }
    }

    int rsize = 3;
    int csize = 3;
    for (int t = 0; t <= 100; ++t)
    {
        if (board[R - 1][C - 1] == K) {
            cout << t;
            return 0;
        }
        int len = 0;
        int nb[101][101];
        memset(nb, 0, sizeof(nb));
        if (rsize >= csize)
        {
            //R
            for (int i = 0; i < rsize; ++i)
            {
                vector<Num> num;
                unordered_map<int, int> cnt;
                for (int j = 0; j < csize; ++j)
                {
                    if (board[i][j] == 0) continue;
                    cnt[board[i][j]]++;
                }
                for (auto j : cnt)
                {
                    num.push_back({ j.first, j.second });
                }
                sort(num.begin(), num.end());
                for (int j = 0; j < num.size() && j < 50; j++)
                {
                    nb[i][j * 2] = num[j].n;
                    nb[i][j * 2 + 1] = num[j].cnt;
                    len = max(len, j * 2 + 2);
                }
            }
            csize = len;
        }
        else
        {
            //C
            for (int i = 0; i < csize; ++i)
            {
                vector<Num> num;
                unordered_map<int, int> cnt;
                for (int j = 0; j < rsize; ++j)
                {
                    if (board[j][i] == 0) continue;
                    cnt[board[j][i]]++;
                }
                for (auto j : cnt)
                {
                    num.push_back({ j.first, j.second });
                }
                sort(num.begin(), num.end());
                for (int j = 0; j < num.size() && j < 50; j++)
                {
                    nb[j * 2][i] = num[j].n;
                    nb[j * 2 + 1][i] = num[j].cnt;
                    len = max(len, j * 2 + 2);
                }
            }
            rsize = len;
        }
        memcpy(board, nb, sizeof(board));

        /*
        for (int i = 0; i < rsize; ++i)
        {
            for (int j = 0; j < csize; ++j)
                cout << board[i][j] << " ";
            cout << "\n";
        }
        cout << "\n";
        */
    }
    cout << -1;
    return 0;
}