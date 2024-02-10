#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
#include <string>
using namespace std;
vector<int> graph1[100001];
vector<int> graph2[100001];
vector<int> s;
int check[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int U, V, X;
    cin >> U >> V >> X;
    for (int i = 0; i < V; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph1[a].push_back(b);
        graph2[b].push_back(a);
    }
    
    int t = -1;
    int d = -1;
    queue<int> q;
    q.push(X);
    check[X] = 1;
    while (!q.empty())
    {
        int qSize = q.size();
        for (int i = 0; i < qSize; ++i)
        {
            int now = q.front();
            q.pop();
            t++;
            for (int j : graph1[now])
            {
                if (check[j] == 0)
                {
                    check[j] = 1;
                    q.push(j);
                }
            }
        }
    }

    for (int i = 1; i <=U; ++i)
    {
        check[i] = 0;
    }

    q.push(X);
    check[X] = 1;
    while (!q.empty())
    {
        int qSize = q.size();
        for (int i = 0; i < qSize; ++i)
        {
            int now = q.front();
            q.pop();
            d++;
            for (int j : graph2[now])
            {
                if (check[j] == 0)
                {
                    check[j] = 1;
                    q.push(j);
                }
            }
        }
    }
    cout << 1 + d << "\n"<< U - t;

    return 0;
}