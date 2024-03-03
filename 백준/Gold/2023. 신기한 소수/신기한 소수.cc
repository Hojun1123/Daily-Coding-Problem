#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int N;
bool check(int n)
{
    for (int i = 2; i <= sqrt(n) + 1; ++i)
    {
        if (i != n && n % i == 0)
        {
            return false;
        }
    }
    return true;
}
void bt(int index, int num)
{
    if (!check(num)) return;
    if (index == N)
    {
        cout << num << "\n";
        return;
    }
    for (int i = 0; i < 10; ++i)
    {
        bt(index + 1, num * 10 + i);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    bt(1, 2);
    bt(1, 3);
    bt(1, 5);
    bt(1, 7);
    return 0;
}