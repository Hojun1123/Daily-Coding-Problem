#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
int L, C;
vector<char> str;
string r = "";
int mo = 0;
int ja = 0;
void bt(int index, int len)
{
    if (len == L)
    {
        if(mo >= 1 && ja >= 2)
            cout << r << "\n";
        return;
    }
    if (index == C)
    {
        return;
    }

    r += str[index];
    bool isMo = false;
    if (str[index] == 'a' || str[index] == 'e' || str[index] == 'i' || str[index] == 'o' || str[index] == 'u')
    {
        isMo = true;
        mo++;
    }
    else
    {
        ja++;
    }
    bt(index + 1, len + 1);
    r.pop_back();
    if (isMo)
    {
        mo--;
    }
    else
    {
        ja--;
    }
    bt(index + 1, len);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> L >> C;
    for (int i = 0; i < C; ++i)
    {
        char a;
        cin >> a;
        str.push_back(a);
    }
    sort(str.begin(), str.end());
    bt(0, 0);
    return 0;
}