#include <iostream>

#include <queue>

#include <vector>

#include <algorithm>

#include <map>

#include <string>

#include <stack>

using namespace std;

map<int, int> m;

int T, N;

int check1[10001];

int check2[10001];

int main()

{

    cin >> T;

    int a, b;

    for (int t = 1; t <= T; ++t)

    {

        cin >> N;

        m = map<int, int>();

        for (int i = 0; i < N - 1; ++i)

        {

            cin >> a >> b;

            m[b] = a;   //child - parent;

        }

        for (int i = 1; i <= N; ++i)

        {

            check1[i] = 0;

            check2[i] = 0;

        }

        //a와 b의 공통 조상 찾기

        cin >> a >> b;

     

        //a

        int curr = a;

        while (true)

        {

            check1[curr] = 1;

            if (m.find(curr) == m.end())

            {

                break;

            }

            else

            {

                curr = m[curr];

            }

        }

        //b

        curr = b;

        while (true)

        {

            check2[curr] = 1;

            if (check1[curr])

            {

                cout << curr << "\n";

                break;

            }

            curr = m[curr];

        }

    }

    return 0;

}