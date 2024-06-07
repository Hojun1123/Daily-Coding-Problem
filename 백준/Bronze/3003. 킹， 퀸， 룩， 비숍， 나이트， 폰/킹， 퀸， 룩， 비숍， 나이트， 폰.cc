#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_map>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c[6] = { 1, 1, 2, 2, 2, 8 };
    for (int i = 0; i < 6; ++i)
    {
        int a;
        cin >> a;
        cout << c[i] - a << " ";
    }
    return 0;
 }