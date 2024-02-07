#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int N, M;
int answer[101][101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (i == j)
                answer[i][j] = 0;
            else
            {
                answer[i][j] = 987654321;
            }
        }
    }
    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if(answer[a][b] > c)
            answer[a][b] = c;
    }
    
    for (int k = 1; k <= N; ++k)
    {
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= N; ++j)
            {
                if (answer[i][k] + answer[k][j] < answer[i][j])
                {
                    answer[i][j] = answer[i][k] + answer[k][j];
                }
            }
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cout << (answer[i][j] >=  987654321 ? 0 : answer[i][j]) << " ";
        }
        cout << "\n";
    }
    return 0;
}