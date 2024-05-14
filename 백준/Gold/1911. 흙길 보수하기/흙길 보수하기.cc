#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
//N 개의 물웅덩이
//L 널빤지를 충분히 가지고 있음

int N, L;
struct Node {
    int s, e;
    bool operator<(Node o) const {
        return s < o.s;
    }
};
Node arr[10000];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> L;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i].s >> arr[i].e;
    }
    sort(arr, arr + N);
    int start = arr[0].s;
    int end = arr[0].e;
    int index = 0;
    int cnt = 0;
    while (true)
    {
        if (start < end) {
            cnt++;
            start += L;
        }
        else {
            index++;
            if (index == N) break;
            start = max(start, arr[index].s);
            end = arr[index].e;
        }
    }
    cout << cnt;
    return 0;
}