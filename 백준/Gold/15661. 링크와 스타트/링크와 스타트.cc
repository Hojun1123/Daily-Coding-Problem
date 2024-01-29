#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <vector>
using namespace std;
int N;
int status = 0;
int arr[20][20];
map<int, int> score;
int answer = 1000000000;
int calculateDiffStatus()
{
    int otherTeamStatus = ~status;
    int startTeam = 0;
    int linkTeam = 0;
    for (auto iter = score.begin(); iter != score.end(); ++iter)
    {
        if ((status & iter->first) == iter->first)
        {
            startTeam += iter->second;
        }
        if ((otherTeamStatus & iter->first) == iter->first)
        {
            linkTeam += iter->second;
        }
    }
    if (linkTeam > startTeam)
        return linkTeam - startTeam;
    else
        return startTeam - linkTeam;
}
void backtracking(int index)
{
    if (index == N)
    {
        int tmp = calculateDiffStatus();
        if (answer > tmp)
            answer = tmp;
        return;
    }
    backtracking(index + 1);
    status |= (1 << index);
    backtracking(index + 1);
    status &= ~(1 << index);
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int index = (1 << i) | (1 << j);
            score[index] = arr[i][j] + arr[j][i];
        }
    }
    backtracking(0);
    cout << answer;
    return 0;
}