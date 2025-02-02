#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int last = 0;
    for (int i = 0; i <= n - m; ++i) {
        cout << i << " " << i + 1 << "\n";
        last = i;
    }
    for (int i = n - m + 1; i < n - 1; ++i) {
        cout << last << " " << i + 1 << "\n";
    }
    return 0;
}