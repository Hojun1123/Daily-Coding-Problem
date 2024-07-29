#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <unordered_map>
using namespace std;
long long G;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> G;
    //현재 몸무게: a
    //기억하던 몸무게: b
    //a*a - b*b 
    // 1 ~ 100000
    long long left = 1;
    long long right = 2;
    int flag = 0;
    while (left < right)
    {
        long long curr = (right * right - left * left);
        if (curr < G)
        {
            right++;
        }
        else if (curr > G)
        {
            left++;
        }
        else
        {
            flag = 1;
            cout << right << "\n";
            right++;
        }
    }
    if (!flag) cout << -1;

    return 0;
}