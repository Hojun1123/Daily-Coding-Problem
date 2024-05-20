#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <string>
#include <unordered_map>
#include <bitset>
#include <stack>
#include <unordered_set>
#include <cstring>
using namespace std;
long long x, y;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> x >> y;
    long long n = -1;
    for (long long i = 1; i < 22222222; ++i)
    {
        if ((i * (i + 1) / 2) == (x + y)) {
            n = i;
            break;
        }
    }
    if (n == -1) {
        cout << -1; return 0;
    }
    int cnt = 0;
    while (x > 0)
    {
        x -= n;
        n--;
        cnt++;
    }
    cout << cnt;
    return 0;
}
