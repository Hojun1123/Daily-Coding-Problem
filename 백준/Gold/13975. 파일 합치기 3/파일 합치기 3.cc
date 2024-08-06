#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <set>
using namespace std;
int N, T;
priority_queue<long long, vector<long long>, greater<long long>> pq;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        cin >> N;
        long long result = 0;
        long long input;
        for (int k = 0; k < N; ++k)
        {
            cin >> input;
            pq.push(input);
        }

        while (pq.size() > 1)
        {
            long long curr = pq.top();
            pq.pop();
            long long prev = pq.top();
            pq.pop();
            long long ss = curr + prev;
            pq.push(ss);
            result += ss;
        }
        pq.pop();
        cout << result << "\n";
    }
    return 0;
}