#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_map>
using namespace std;
struct Node {
    int a, b;
};
int N, M;
int connectCnt[100001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        connectCnt[a] ++;
        connectCnt[b] ++;
    }
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        if (a == 1) {
            if (connectCnt[b] > 1) {
                cout << "yes\n";
            }
            else {
                cout << "no\n";
            }
        }
        else {
            cout << "yes\n";
        }
    }
    return 0;
 }