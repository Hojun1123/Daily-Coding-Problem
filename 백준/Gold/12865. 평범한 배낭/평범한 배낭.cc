#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>
#include <deque>
#include <deque>
#include <map>
#include <vector>
#include <sstream>
using namespace std;
int N, M;
int answer[101][100001];
int arr[101][2];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        int a, b;
        cin >> a >> b;
        arr[i][0] = a;
        arr[i][1] = b;
        answer[i][a] = b;
    }
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            if (j - arr[i][0] >= 0)
                answer[i][j] = max(answer[i - 1][j], answer[i - 1][j - arr[i][0]] + arr[i][1]);
            else
                answer[i][j] = answer[i - 1][j];
        }
    }
    cout << answer[N][M];
    return 0;
}