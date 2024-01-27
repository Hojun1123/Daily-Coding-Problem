#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <vector>
using namespace std;
int check[10];
int T, N, K;
bool isFinished()
{
    for (int i = 0; i < 10; ++i)
    {
        if (check[i])
            continue;
        return false;
    }
    return true;
}
void checkNum(int num)
{
    while (num)
    {
        check[num % 10] = 1;
        num /= 10;
    }
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        cin >> N;
        K = 0;
        for (int i = 0; i < 10; ++i)
            check[i] = 0;

        while (!isFinished())
        {
            K++;
            checkNum(N * K);
        }

        cout << "#" << t << " " << N*K << "\n";
    }
    
    return 0;
}