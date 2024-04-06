#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <string>
#include <unordered_map>
#include <bitset>
#include <stack>
#include <unordered_set>
#include <cstring>
using namespace std;
struct xy {
    int y, x;
};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    xy A, B, C;
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
    xy AB = { B.y - A.y, B.x - A.x };
    //cout << AB.y << AB.x <<"\n";
    xy BC = { C.y - B.y, C.x - B.x };
    //cout << BC.y << BC.x <<"\n";
    int r = AB.x* BC.y - AB.y * BC.x;
    //cout << r;
    if (r > 0)cout << 1;
    else if (r < 0) cout << -1;
    else cout << 0;
        
    return 0;
}
 