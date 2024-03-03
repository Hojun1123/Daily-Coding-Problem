#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <deque>
#include <unordered_map>
#include <cstring>

using namespace std;
int N;
string str;
vector<char> op;
vector<int> num;
int used[10];
int result[10];
int answer = -2147483648;
void cal()
{
    int tmp[10];
    for (int i = 0; i < num.size(); ++i)
    {
        tmp[i] = num[i];
    }
    for (int i = 0; i < op.size(); ++i)
    {
        if (used[i])
        {
            char curr = op[i];
            int ret = 0;
            if (curr == '+')
            {
                ret = num[i] + num[i + 1];
            }
            else if (curr == '-')
            {
                ret = num[i] - num[i + 1];
            }
            else
            {
                ret = num[i] * num[i + 1];
            }
            tmp[i] = tmp[i + 1] = ret;
        }
    }
    int prev = tmp[0];
    for (int i = 0; i < op.size(); ++i)
    {
        if (!used[i])
        {
            char curr = op[i];
            if (curr == '+')
            {
                prev += tmp[i + 1];
            }
            else if (curr == '-')
            {
                prev -= tmp[i + 1];
            }
            else
            {
                prev *= tmp[i + 1];
            }
        }
    }
    if (prev > answer) answer = prev;
}
void bt(int depth)
{
    cal();
    if (depth >= op.size())
    {
        cal();
        return;
    }
    bt(depth + 1);
    used[depth] = 1;
    bt(depth + 2);
    used[depth] = 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    cin >> str;
    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            num.push_back(str[i] - '0');
        }
        else
        {
            op.push_back(str[i]);
        }
    }
    bt(0);
    cout << answer;
    return 0;
}