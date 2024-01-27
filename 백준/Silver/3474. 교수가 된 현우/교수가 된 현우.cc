#include <iostream>
using namespace std;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int k = 0; k < t; ++k)
    {
        long long answer = 0;
        long long base = 5;
        int n;
        cin >> n;
        for (int i = 5; i <= n; i *= 5)
        {
            answer += n / i;
        }
        cout << answer << "\n";
    }
    return 0;
}