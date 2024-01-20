#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
using namespace std;
int x, y, T, D;
double cases[3];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.fixed;
    cout.precision(10);
    cin >> x >> y >> D >> T;

    for (int i = 0; i < 3; ++i)
        cases[i] = 987654321;

    double distance;
    distance = sqrt(x * x + y * y);
    //걷기로만 이동
    cases[0] = distance;
    double a = distance / D;
    if (int(a) >= 1)
    {
        if (a - (int)a == 0)
        {   //점프로만 이동
            cases[1] = (int)a * T;
        }
        else
        {
            //원점 근처까지 점프 후, 걷기
            cases[1] = ((int)a + 1) * T;
            //점프로 원점을 지나친 후, 걷기
            cases[2] = (int)a * T + (distance - (int)a * D);
        }

    }
    else
    {
        //점프로만 이동(2번)
        cases[1] = 2 * T;
        //점프로 원점을 지나친 후, 걷기
        cases[2] = T + (D - distance);
    }

    double answer = cases[0];
    for (int i = 1; i < 3; ++i)
    {
        if (answer > cases[i])
            answer = cases[i];
    }
    cout << answer;
    return 0;
}