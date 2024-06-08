#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_map>
using namespace std;
//게임횟수 N, 플레이어 정보P
int N, P;
int W, L, G;
unordered_map<string, int> player;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> P;
    cin >> W >> L >> G;
    for (int i = 0; i < P; ++i)
    {
        string name;
        char tt;
        cin >> name >> tt;
        if (tt == 'W') {
            player[name] = 1;
        }
        else {
            player[name] = -1;
        }
    }
    int start = 0;
    int flag = 0;
    for (int i = 0; i < N; ++i) {
        string name;
        cin >> name;
        if (player.find(name) == player.end())
            start -= L;
        else if (player[name] == 1)
            start += W;
        else
            start -= L;

        if (start < 0) start = 0;
        if (start >= G) flag = 1;
    }
    cout << "I AM ";
    cout << (flag ? "NOT " : "");
    cout << "IRONMAN!!";

    
    return 0;
 }