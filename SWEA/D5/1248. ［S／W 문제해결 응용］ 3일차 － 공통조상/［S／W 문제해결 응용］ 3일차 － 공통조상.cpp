#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <stack>
using namespace std;
map<int, int> m;
map<int, vector<int>> tree;
int checkA[10001] = {};
int checkB[10001] = {};
int main()
{
    int test_case;
    int T;
    string s;
    cin >> T;
    
    int V, E, A, B; //정점, 간선, A , B
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> V >> E >> A >> B;
        
        int p, c;
        m = map<int, int>();
        tree = map<int, vector<int>>();
        for (int i = 0; i < E; ++i)
        {
            cin >> p >> c;
            m[c] = p;
            tree[p].push_back(c);
        }
        for (int i = 1; i <= V; ++i)
        {
            checkA[i] = 0;
            checkB[i] = 0;
        }

        int result = 1;
        int curr = A;
        while (true)
        {
            if (m.find(curr) == m.end())
            {
                break;
            }
            else
            {
                checkA[m[curr]] = 1;
                curr = m[curr];
            }
        }

        //b
        curr = B;
        while (true)
        {
            if (m.find(curr) == m.end())
            {
                break;
            }
            else
            {
                checkB[m[curr]] = 1;
                curr = m[curr];
                if (checkA[curr])
                {
                    result = curr;
                    break;
                }
            }
        }

        for (int i = 1; i <= V; ++i)
        {
            checkA[i] = 0;
        }

        stack<int> s;
        s.push(result);
        int tmp;
        int cnt = 1;
        while (!s.empty())
        {
            tmp = s.top();
            s.pop();
            for (int i = 0; i < tree[tmp].size(); ++i)
            {
                s.push(tree[tmp][i]);
                cnt += 1;
            }
        }
        

        cout << "#" << test_case << " "<< result << " " << cnt << "\n";
    }
    return 0;
}