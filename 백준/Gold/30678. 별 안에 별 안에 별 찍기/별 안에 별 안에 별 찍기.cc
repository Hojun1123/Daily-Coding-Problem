#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
using namespace std;
int N;
typedef struct yx{
    int y;
    int x;
} yx;
vector<yx> v = {
    {0, 2}, {1, 2},
    {2, 0}, {2, 1}, {2, 2}, {2, 3}, {2, 4},
    {3, 1}, {3, 2}, {3, 3},
    {4, 1}, {4, 3}
};
int check[4000][4000];
void recursion(int pn, int y, int x)
{
    //cout << y << " " << x << "\n";
    if(pn == 0)
    {
        check[y][x] = 1;
        return;
    }
    for(int i = 0; i < v.size(); ++i)
    {
        recursion(pn / 5, y + pn*v[i].y, x + pn*v[i].x);
    }
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   cin >> N;
   int pn = 1;
   for(int i = 0; i < N; ++i)
       pn *= 5;
   recursion(pn / 5, 0, 0);
   for(int i = 0; i < pn; ++i)
   {
       for(int j = 0; j < pn; ++j)
       {
           cout << (check[i][j] ? "*": " ");
       }
       cout << "\n";
   }
   return 0;
}
