#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
#include <string>
using namespace std;
string A, S;
map<char, int> m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> S;
    A = S;
    int n = 1;
    int answer = 0;
    
    char prev = S[0];
    m[prev]++;
    if (prev == '(')
        n *= 2;
    else if (prev == '[')
        n *= 3;
    else
    {
        cout << 0;
        return 0;
    }
    for (int i = 1; i < S.size(); ++i)
    {
        if (S[i] == '(')
        {
            m['('] ++;
            n *= 2;
        }
        else if (S[i] == ')')
        {
            m['('] --;
            if (prev == '[')
            {
                cout << 0;
                return 0;
            }
            if (prev == '(')
            {
                answer += n;
            }
            n /= 2;
        }
        else if (S[i] == '[')
        {
            m['['] ++;
            n *= 3;
        } 
        else
        {
            m['['] --;
            if (prev == '(')
            {
                cout << 0;
                return 0;
            }
            if(prev == '[')
            {
                answer += n;
            }
            n /= 3;
        }
        prev = S[i];
    }
    if (m['('] == 0 && m['['] == 0)
        cout << answer;
    else
        cout << 0;
    return 0;
}