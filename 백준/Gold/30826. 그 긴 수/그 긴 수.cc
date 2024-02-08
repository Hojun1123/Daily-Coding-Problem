#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
#include <string>
using namespace std;
long long K;
long long odd = 9;
long long even = 9;
void recursion(int length, long long index)
{
   // cout << index << " ";
    long long tmp;
    if (length % 2 == 1)
    {
        tmp = index + odd * length;
        if (tmp > K)
        {
            long long n = (K - index) / length;
            long long nl = (K - index) % length;
            long long ten = 1;
            for (int i = 0; i < length / 2; ++i)
            {
                ten *= 10;
            }
            string itos = to_string(ten + n);
            string re = itos;
            for (int i = itos.size() - 2; i >= 0; --i)
            {
                re += itos[i];
            }
            cout << re[nl];
            return;
        }
        odd *= 10;
    }
    else
    {
        tmp = index + even * length;
        if (tmp > K)
        {
            long long n = (K - index) / length;
            long long nl = (K - index) % length;
            long long ten = 1;
            for (int i = 0; i < length / 2 - 1; ++i)
            {
                ten *= 10;
            }
            string itos = to_string(ten + n);
            string re = itos;
            for (int i = itos.size() - 1; i >= 0; --i)
            {
                re += itos[i];
            }
            cout << re[nl];
            return;
        }
        even *= 10;
    }
    recursion(length + 1, tmp);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> K;
    recursion(1, 1);
    return 0;
}