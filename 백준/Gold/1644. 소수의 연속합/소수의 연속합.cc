#include <iostream>
#include <vector>
#include <map>
#include <deque>
#include <list>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <cstring>
#include <list>
using namespace std;
int N;
int arr[4000001];
vector<int> v;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    if (N == 1) {
        cout << 0; return 0;
    }
    arr[0] = 1;
    arr[1] = 1;
    for (int i = 2; i <= 2000; ++i)
    {
        if (arr[i]) continue;
        for (int j = i + i; j <= N; j += i)
        {
            arr[j] = 1;
        }
    }
    for (int i = 2; i <= N; ++i)
    {
        if (!arr[i]) v.push_back(i);
    }
    int left = 0;
    int right = 1;
    int s = v[0];
    int cnt = 0;
    while (right < v.size())
    {
        //cout << v[left] << " " << v[right] << " " << s << "\n";
        if (s == N)
        {
            cnt++;
            s -= v[left];
            left++;
        }
        else if (s > N)
        {
            s -= v[left];
            left++;
        }
        else
        {
            s += v[right];
            right++;
        }
    }
    if (arr[N] == 0) cnt++;
    cout << cnt;
    return 0;
}
