#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int M;
long long sum = 0;
int axor = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a;
        if (a == 1)
        {
            cin >> b;
            sum += b;
            axor ^= b;
        }
        else if (a == 2)
        {
            cin >> b;
            axor ^= b;
            sum -= b;
        }
        else if (a == 3)
        {
            cout << sum << "\n";
        }
        else {
            cout << axor << "\n";
        }
    }
    return 0;
}