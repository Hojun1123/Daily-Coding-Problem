#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <deque>
#include <unordered_map>
#include <cstring>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string a, b;
    cin >> a >> b;
    int cnt = 0;
    while (b.size() != 0)
    {
        for (int i = b.size(); i >= 0; --i)
        {
            if (a.find(b.substr(0, i)) != string::npos)
            {
                b.erase(0, i);
                break;
            }
        }
        cnt++;
    }
    cout << cnt;
    return 0;
}