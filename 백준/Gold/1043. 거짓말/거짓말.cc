#include <iostream>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
int N, M;   //사람 수, 파티 수
int check[51];
int knownPeopleNum;
vector<int> knownPeople;
int party[50][51];
int answer = 0;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    cin >> knownPeopleNum;
    int input;
    for (int i = 0; i < knownPeopleNum; ++i)
    {
        cin >> input;
        knownPeople.push_back(input);
    }

    for (int i = 0; i < M; ++i)
    {
        cin >> party[i][0];
        for (int j = 1; j <= party[i][0]; ++j)
        {
            cin >> party[i][j];
        }
    }

    for (int i = 0; i < knownPeople.size(); ++i)
    {
        int temp;
        stack<int> s;
        s.push(knownPeople[i]);
        check[knownPeople[i]] = 1;
        int p;
        while (!s.empty())
        {
            temp = s.top();
            s.pop();
            vector<int> loop;
            for (int j = 0; j < M; ++j)
            {
                for (int k = 1; k <= party[j][0]; ++k)
                {
                    if (party[j][k] == temp)
                    {
                        loop.push_back(j);
                        break;
                    }
                }
            }

            for (int j = 0; j < loop.size(); ++j)
            {
                for (int k = 1; k <= party[loop[j]][0]; ++k)
                {
                    if (check[party[loop[j]][k]] == 0)
                    {
                        s.push(party[loop[j]][k]);
                        check[party[loop[j]][k]] = 1;
                    }
                }
            }

        }
    }

    for (int i = 0; i < M; ++i)
    {
        bool c = true;
        for (int j = 1; j <= party[i][0]; ++j)
        {
            if (check[party[i][j]])
            {
                c = false;
                break;
            }
        }

        if (c)
        {
            answer++;
        }
    }
    cout << answer;
    return 0;
}