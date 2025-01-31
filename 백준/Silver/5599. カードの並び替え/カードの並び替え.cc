#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;
int N, M;
int card[200];
int newCard[200];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    int op;
    for (int i = 1; i <= N * 2; ++i) {
        card[i - 1] = i;
    }
    for (int i = 0; i < M; ++i) {
        cin >> op;
        if(op == 0){
            for (int k = 0; k < N; ++k) {
                newCard[2 * k] = card[k];
                newCard[2 * k + 1] = card[N + k];
            }
        }
        else {
            int index = 0;
            for (int k = op; k < 2 * N; ++k) {
                newCard[index++] = card[k];
            }
            for (int k = 0; k < op; ++k) {
                newCard[index++] = card[k];
            }
        }
        memcpy(card, newCard, sizeof(card));
    }
    for (int i = 0; i < 2 * N; ++i) cout << card[i] << "\n";
    return 0;
}