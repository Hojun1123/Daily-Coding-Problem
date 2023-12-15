#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <numeric>
#include <stack>
using namespace std;
int N, M;
map<int, vector<int>> m;
int check[101];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cin >> M;
    int a, b;

    stack<int> s;
    for (int i = 0; i < M; ++i)
    {
        cin >> a;
        cin >> b;
        m[a].push_back(b);
        m[b].push_back(a);

    }

    s.push(1);
    vector<int> curr;
    int temp;
    while (!s.empty())
    {
        temp = s.top();
        s.pop();
        check[temp] = 1;
        
        curr = m[temp];
        for (int i = 0; i < curr.size(); ++i)
        {
            if (check[curr[i]] == 0)
                s.push(curr[i]);
        }
    }

    int answer = 0;
    for (int i = 2; i <= N; ++i)
    {
        if (check[i])
            answer += 1;
    }
    cout << answer;

    return 0;
}