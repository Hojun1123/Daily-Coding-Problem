#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
#include <string>
using namespace std;
int N;
struct node {
    int s, t;
    bool operator<(node o) const {
        if (s < o.s) return false;
        else if (s > o.s) return true;
        return t > o.t;
    }
};
priority_queue<node> arr;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int a, b;
        cin >> a >> b;
        arr.push({ a, 1 });
        arr.push({ b, -1 });
    }
    
    int nCnt = 0;
    int answer = 0;
    while (!arr.empty())
    {
        auto curr = arr.top();
        arr.pop();
        nCnt += curr.t;
        if (nCnt > answer)
        {
            answer = nCnt;
        }
    }

    cout << answer;
    return 0;
}