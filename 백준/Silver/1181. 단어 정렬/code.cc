#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
using namespace std;

int N,M;
map<int, priority_queue<string, vector<string>, greater<>>> m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    string s;
    for(int i = 0; i < N; ++i)
    {
        cin >> s;
        m[s.size()].push(s);
    }
    for(auto iter = m.begin(); iter != m.end(); iter++)
    {
        auto tmp = iter->second;
        string prev = "";
        string curr;
        while(!tmp.empty())
        {
            curr = tmp.top();
            if(prev != curr)
                cout << curr << "\n";
            prev = curr;
            tmp.pop();
        }
    }
    return 0;
}
