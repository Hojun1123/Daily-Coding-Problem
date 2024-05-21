#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <string>
#include <unordered_map>
#include <bitset>
#include <stack>
#include <unordered_set>
#include <cstring>
using namespace std;
int N;
string arr[11111];
string f(string a, string b)
{
    string ret;
    while (a.size() != b.size())
    {
        b = '0' + b;
    }

    int carry = 0;
    for (int i = a.size() - 1; i >= 0; --i)
    {
        int q = a[i] - '0';
        int p = b[i] - '0';
        int s = q + p + carry;
        carry = 0;
        if (s > 9)
        {
            carry = 1;
            ret += char(s % 10 + '0');
        }
        else
        {
            ret += char(s + '0');
        }
    }

    if (carry)
    {
        ret += '1';
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    arr[0] = "0";
    arr[1] = "1";
    for (int i = 2; i <= N; ++i)
    {
        arr[i] = f(arr[i - 1], arr[i - 2]);
    }
    cout << arr[N];
    return 0;
}
