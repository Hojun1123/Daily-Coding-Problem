#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <set>
using namespace std;
int A, B, C;
set<int> ans;
int check[200][200][200];
struct Node {
    int a, b, c;
};
queue<Node> q;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> A >> B >> C;
    check[0][0][C] = 1;
    q.push({ 0, 0, C });
    while (!q.empty())
    {
        Node now = q.front();
        q.pop();
        int a = now.a;
        int b = now.b;
        int c = now.c;
        if(a == 0) ans.insert(c);
        //a -> b
        if(a > 0)
        {
            if (a + b <= B && check[0][a + b][c] == 0)
            {
                check[0][a + b][c] = 1;
                q.push({ 0, a + b, c });
            }
            else if (a + b > B && check[a - (B - b)][B][c] == 0)
            {
                check[a - (B - b)][B][c] = 1;
                q.push({ a - (B - b), B, c });
            }
            if (a + c <= C && check[0][b][a + c] == 0)
            {
                check[0][b][a + c] = 1;
                q.push({ 0, b, a + c });
            }
            else if (a + c > C && check[a - (C - c)][b][C] == 0)
            {
                check[a - (C - c)][b][C] = 1;
                q.push({ a - (C - c), b, C });
            }
        }
        if (b > 0)
        {
            if (b + a <= A && check[b + a][0][c] == 0)
            {
                check[b + a][0][c] = 1;
                q.push({ b + a, 0, c });
            }
            else if (a + b > A && check[A][b - (A - a)][c] == 0)
            {
                check[A][b - (A - a)][c] = 1;
                q.push({ A, b - (A - a), c});
            }
            if (b + c <= C && check[a][0][b + c] == 0)
            {
                check[a][0][b + c] = 1;
                q.push({ a, 0, b + c });
            }
            else if (b + c > C && check[a][b - (C - c)][C] == 0)
            {
                check[a][b - (C - c)][C] = 1;
                q.push({ a, b - (C - c), C });
            }
        }
        if (c > 0)
        {
            if (a + c <= A && check[a + c][b][0] == 0)
            {
                check[a + c][b][0] = 1;
                q.push({ a + c, b, 0 });
            }
            else if (a + c > A && check[A][b][c - (A - a)] == 0)
            {
                check[A][b][c - (A - a)] = 1;
                q.push({ A, b, c - (A - a)});
            }
            if (b + c <= B && check[a][b + c][0] == 0)
            {
                check[a][b + c][0] = 1;
                q.push({ a, b + c, 0 });
            }
            else if (b + c > B && check[a][B][c - (B - b)] == 0)
            {
                check[a][B][c - (B - b)] = 1;
                q.push({ a, B, c - (B - b)});
            }
        }
    }
    for (auto iter = ans.begin(); iter != ans.end(); ++iter)
    {
        cout << *iter << " ";
    }
    return 0;
}