#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>
#include <deque>
#include <deque>
#include <map>
#include <vector>
#include <sstream>
using namespace std;
int N;
int board[20][20];
int maxValue = 0;
deque<int> q;
void dfs(int depth)
{
    // exit 
    if (depth == 5)
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (maxValue < board[i][j])
                {
                    maxValue = board[i][j];
                }
            }
        }
        return;
    }
    // save origin
    //cout << "\n\n";
    int tmpBoard[20][20];
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            tmpBoard[i][j] = board[i][j];
            //cout << board[i][j] << " ";
        }
        //cout << "\n";
    }

    //T
    for (int j = 0; j < N; ++j)
    {
        for (int i = 0; i < N; ++i)
        {
            //cout << board[i][j];

            if (board[i][j] == 0) continue;
            if (q.empty())
            {
                q.push_back(board[i][j]);
            }
            else
            {
                if (q.back() == board[i][j])
                {
                    q.pop_back();
                    q.push_back(board[i][j] * -2);
                }
                else
                {
                    q.push_back(board[i][j]);
                }
            }
        }
        int index = 0;
        while (!q.empty())
        {
            board[index][j] = (q.front() < 0 ? q.front() * -1 : q.front());
            index++;
            q.pop_front();
        }
        for (int k = index; k < N; ++k)
        {
            board[k][j] = 0;
        }
    }
    dfs(depth + 1);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            board[i][j] = tmpBoard[i][j];
        }
    }
    
    //R
    for (int i = 0; i < N; ++i)
    {
        for (int j = N - 1; j >= 0; --j)
        {
            if (board[i][j] == 0) continue;
            if (q.empty())
            {
                q.push_back(board[i][j]);
            }
            else
            {
                if (q.back() == board[i][j])
                {
                    q.pop_back();
                    q.push_back(board[i][j] * -2);
                }
                else
                {
                    q.push_back(board[i][j]);
                }
            }
        }
        int index = N - 1;
        while (!q.empty())
        {
            board[i][index--] = (q.front() < 0 ? q.front() * -1 : q.front());
            q.pop_front();
        }
        for (int k = index; k >= 0; --k)
        {
            board[i][k] = 0;
        }
    }
    dfs(depth + 1);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            board[i][j] = tmpBoard[i][j];
        }
    }
    //B
    for (int j = 0; j < N; ++j)
    {
        for (int i = N - 1; i >= 0; --i)
        {
            if (board[i][j] == 0) continue;
            if (q.empty())
            {
                q.push_back(board[i][j]);
            }
            else
            {
                if (q.back() == board[i][j])
                {
                    q.pop_back();
                    q.push_back(board[i][j] * -2);
                }
                else
                {
                    q.push_back(board[i][j]);
                }
            }
        }
        int index = N - 1;
        while (!q.empty())
        {
            board[index--][j] = (q.front() < 0 ? q.front() * -1 : q.front());
            q.pop_front();
        }
        for (int k = index; k >= 0; --k)
        {
            board[k][j] = 0;
        }
    }
    dfs(depth + 1);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            board[i][j] = tmpBoard[i][j];
        }
    }
    //L
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (board[i][j] == 0) continue;
            if (q.empty())
            {
                q.push_back(board[i][j]);
            }
            else
            {
                if (q.back() == board[i][j])
                {
                    q.pop_back();
                    q.push_back(board[i][j] * -2);
                }
                else
                {
                    q.push_back(board[i][j]);
                }
            }
        }
        int index = 0;
        while (!q.empty())
        {
            board[i][index++] = (q.front() < 0 ? q.front() * -1 : q.front());
            q.pop_front();
        }
        for (int k = index; k < N; ++k)
        {
            board[i][k] = 0;
        }
    }
    dfs(depth + 1);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            board[i][j] = tmpBoard[i][j];
        }
    }
    
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
            cin >> board[i][j];
        }
    }
    dfs(0);
    cout << maxValue;
    return 0;
}