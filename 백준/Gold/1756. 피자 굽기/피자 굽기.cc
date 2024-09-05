#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <stack>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>
using namespace std;
int N, M;
int arr[300003];
int pizza[300000];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    cin >> arr[0];
    for (int i = 1; i < N; ++i) {
        cin >> arr[i];
        if (arr[i - 1] < arr[i]) arr[i] = arr[i - 1];
    }
    for (int i = 0; i < M; ++i) {
        cin >> pizza[i];
    }
    int idx = 0;
    for (int i = N - 1; i >= 0; --i)
    {
        if (arr[i] >= pizza[idx]) {
            idx++;
        }
        if (idx == M) {
            cout << i + 1;
            return 0;
        }
    }
    cout << 0;
    return 0;
}