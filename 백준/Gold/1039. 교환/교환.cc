#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <cstring>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;
int N, K;
int check[2][1000001];
int len;
struct ab {
    int a, b;
};
vector<ab> v;
queue<int> q;
int convert(int num, ab now)
{
    string sN = to_string(num);
    char a = sN[now.a];
    char b = sN[now.b];
    if (now.a == 0 && (a == '0' || b == '0')) return -1;
    sN[now.b] = a;
    sN[now.a] = b;
    return stoi(sN);
}
void solve()
{
    cin >> N >> K; 
    len = to_string(N).size();
    for (int i = 0; i < len - 1; ++i)
    {
        for (int j = i + 1; j < len; ++j)
        {
            v.push_back({ i, j });
        }
    }
    
    q.push(N);
    check[0][N] = 1;
    int cnt = 0;
    int oddMax = -1;
    int evenMax = -1;
    while (!q.empty())
    {
        int qSize = q.size();
        for (int i = 0; i < qSize; ++i)
        {
            int now = q.front();
            q.pop();
            if (cnt % 2)
            {
                oddMax = max(oddMax, now);
            }
            else
            {
                evenMax = max(evenMax, now);
            }
            for (ab j : v)
            {
                int next = convert(now, j);
                if (next == -1) continue;
                if (check[(cnt + 1) % 2][next]) continue;
                check[(cnt + 1) % 2][next] = 1;
                q.push(next);
            }
        }
        if (cnt == K) break;
        cnt++;
    }
    
    if (N <= 10 || (N < 100 && N % 10 == 0)) cout << -1;
    else {
        if (K % 2)
        {
            cout << oddMax;
        }
        else
        {
            cout << evenMax;
        }
    }
}

int main()

{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    solve();
    return 0;

}