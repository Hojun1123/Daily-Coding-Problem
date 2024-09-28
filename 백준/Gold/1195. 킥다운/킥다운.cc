#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
using namespace std;
string a;
string b;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b;
    //a랑 b를하는데
    int ans = 9876;
    for (int i = 0; i <= a.size(); ++i)
    {
        int len = max(a.size(), i + b.size());
        int r = false;
        for (int j = i; j < i + b.size() && j < a.size(); ++j) {
            if (a[j] == '2' && b[j - i] == '2') {
                r = true;
                break;
            }
        }
        if (r)continue;
        ans = min(ans, len);
    }
    for (int i = 0; i <= b.size(); ++i)
    {
        int len = max(b.size(), i + a.size());
        int r = false;
        for (int j = i; j < i + a.size() && j < b.size(); ++j) {
            if (b[j] == '2' && a[j - i] == '2') {
                r = true;
                break;
            }
        }
        if (r)continue;
        ans = min(ans, len);
    }
    cout << ans;
    return 0;
}