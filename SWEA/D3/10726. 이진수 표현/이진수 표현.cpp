#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <vector>
using namespace std;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        int N, M;
        cin >> N >> M;
        int checkBit = (1 << N) - 1;
        cout << "#" << t << " " << ((M & checkBit) == checkBit ? "ON" : "OFF") << "\n";
    }
    
    return 0;
}