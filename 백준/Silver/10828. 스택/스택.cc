#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <numeric>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int inputSize;
    cin >> inputSize;
    string in;
    stack<int> s;
    int a;

    for (int i = 0; i < inputSize; ++i)
    {
        cin >> in;
        if (in == "push")
        {
            cin >> a;
            s.push(a);
        }
        else if (in == "pop")
        {
            if (s.empty())
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << s.top() << "\n";
                s.pop();
            }
        }
        else if (in == "size")
        {
            cout << s.size() << "\n";
        }
        else if (in == "empty")
        {
            cout << s.empty() << "\n";
        }
        else
        {
            if (s.empty())
            {
                cout << -1 << "\n";
            }
            else
                cout << s.top() << "\n";
        }
    }
    return 0;
}