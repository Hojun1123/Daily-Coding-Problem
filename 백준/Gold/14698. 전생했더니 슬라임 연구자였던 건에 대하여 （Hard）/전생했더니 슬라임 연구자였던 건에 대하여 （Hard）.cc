#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
int T, N;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    unsigned long long a, b;
    for (int tc = 0; tc < T; ++tc)
    {
        cin >> N;
        priority_queue<unsigned long long, vector<unsigned long long>, greater<unsigned long long>> minq;
        for (int i = 0; i < N; ++i)
        {
            cin >> a;
            minq.push(a);
        }
        
        unsigned long long result = 1;
        while(true)
        {
            if (minq.size() < 2)
                break;
            a = minq.top();
            minq.pop();
            unsigned long long tmp = minq.top() * a;
            minq.pop();
            minq.push(tmp);
            tmp %= 1000000007;
            result = (result * tmp) % 1000000007;
        }
        cout << result << "\n";
    }
    return 0;
}