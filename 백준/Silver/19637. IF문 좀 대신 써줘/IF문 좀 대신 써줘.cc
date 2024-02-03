#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <vector>
using namespace std;
int N, K;
vector<int> input;
struct d {
    int n;
    string s;
    int seq;

    bool operator<(d other) const {
        if (n < other.n) return false;
        else if (n > other.n) return true;
        return false;
    }
};
priority_queue<d> pq;
queue<d> q;
string answer[100000];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> N >> K;
    string a;
    int b;
    for (int i = 0; i < N; ++i)
    {
        cin >> a >> b;
        q.push({ b, a, 0});
    }

    for (int i = 0; i < K; ++i)
    {
        cin >> b;
        pq.push({ b, "", i});
    }

    while (!pq.empty())
    {
        int nowNum = pq.top().n;
        if (nowNum <= q.front().n)
        {
            answer[pq.top().seq] = q.front().s;
        }
        else
        {
            while (true)
            {
                q.pop();
                if (nowNum <= q.front().n)
                    break;
            }
            answer[pq.top().seq] = q.front().s;
        }
        pq.pop();
    }
    for(int i = 0; i < K; ++i)
        cout << answer[i] << "\n";
    return 0;
}