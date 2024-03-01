#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <deque>
#include <unordered_map>
#include <cstring>
using namespace std;
int N, L;
int arr[100][100];
int mem[100];
int cnt = 0;
bool check1(int nn, int n, int h)
{
    if (n - L + 1 < 0) return false;
    for (int i = 0; i < L; ++i)
    {
        if (arr[nn][n - i] == h && mem[n - i] == 0) continue;
        return false;
    }
    for (int i = 0; i < L; ++i)
    {
        mem[n - i] = 1;
    }
    return true;
}
bool check2(int nn, int n, int h)
{
    if (n + L > N)return false;
    for (int i = 0; i < L; ++i)
    {
        if (arr[nn][n + i] == h && mem[n + i] == 0) continue;
        return false;
    }
    for (int i = 0; i < L; ++i)
    {
        mem[n + i] = 1;
    }
    return true;
}
bool check3(int n, int nn, int h)
{
    if (n - L + 1 < 0) return false;
    for (int i = 0; i < L; ++i)
    {
        if (arr[n - i][nn] == h && mem[n - i] == 0) continue;
        return false;
    }
    for (int i = 0; i < L; ++i)
    {
        mem[n - i] = 1;
    }
    return true;
}
bool check4(int n, int nn, int h)
{
    if (n + L > N)return false;
    for (int i = 0; i < L; ++i)
    {
        if (arr[n + i][nn] == h && mem[n + i] == 0) continue;
        return false;
    }
    for (int i = 0; i < L; ++i)
    {
        mem[n + i] = 1;
    }
    return true;

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> L;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < N; ++i)
    {
        int index = 1;
        int prevHeight = arr[i][0];
        memset(mem, 0, sizeof(mem));
        while(true)
        {
            if (index == N) {
                cnt++;
                break;
            }
            if (prevHeight == arr[i][index])
            {
                index++;
                continue;
            }
            int diff = arr[i][index] - prevHeight;
            if (diff == 1)
            {
                if (!check1(i, index - 1, prevHeight)) break;
            }
            else if (diff == -1)
            {
                if (!check2(i, index, arr[i][index])) break;
            }
            else
            {
                //불가능
                break;
            }
            prevHeight = arr[i][index];
            index++;
        }
    }
    for (int i = 0; i < N; ++i)
    {
        int index = 1;
        int prevHeight = arr[0][i];
        memset(mem, 0, sizeof(mem));
        while (true)
        {
            if (index == N) {
                cnt++;
                break;
            }
            if (prevHeight == arr[index][i])
            {
                index++;
                continue;
            }
            int diff = arr[index][i] - prevHeight;
            if (diff == 1)
            {
                if (!check3(index - 1, i, prevHeight)) break;
            }
            else if (diff == -1)
            {
                if (!check4(index, i, arr[index][i])) break;
            }
            else
            {
                //불가능
                break;
            }
            prevHeight = arr[index][i];
            index++;
        }
    }
    cout << cnt;
    return 0;
}