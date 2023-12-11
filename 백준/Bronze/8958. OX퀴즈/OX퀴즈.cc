#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <numeric>
#include <stack>
using namespace std;
string a;
int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> a;
        int cnt = 0;
        int score = 0;
        for (int j = 0; j < a.size(); ++j)
        {
            if (a[j] == 'O')
            {
                cnt += 1;
                score += cnt;
            }
            else
            {
                cnt = 0;
            }
        }
        cout << score << "\n";
    }
    return 0;
}