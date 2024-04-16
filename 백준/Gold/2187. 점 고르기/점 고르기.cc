#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <cmath>
#include <unordered_map>
using namespace std;
int N, A, B;
struct dot {
    int y, x, w;
};
vector<dot> v;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> A >> B;
    for (int i = 0; i < N; ++i)
    {
        int r, c, s;
        cin >> r >> c >> s;
        v.push_back({ r, c, s });
    }

    int ans = 0;
    for (int i = 0; i < N - 1; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            dot& a = v[i];
            dot& b = v[j];
            int weight = abs(a.w - b.w);
            if (weight <= ans) continue;
            //cout << weight << "\n";
            if (abs(a.y - b.y) < A && abs(a.x - b.x) < B)
            {
                ans = weight;
            }
        }
    }
    cout << ans;
    return 0;
}
