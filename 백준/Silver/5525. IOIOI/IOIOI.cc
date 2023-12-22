#include <iostream>
using namespace std;

int N, M;
string S;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    cin >> M;
    cin >> S;
    string f_str;
    for (int i = 0; i < N * 2 + 1; ++i)
    {
        f_str.append((i % 2) ? "O" : "I");
    }

    int index = 0;
    int answer = 0;
    
    while (index != M)
    {
        if (S[index++] == 'I')
        {
            int cnt = 0;
            while (true)
            {
                if (S[index] == 'O' && S[index + 1] == 'I')
                {
                    cnt++;
                    index += 2;
                }
                else
                {
                    break;
                }
                if (cnt >= N)
                    answer++;
            }
        }
    }
    cout << answer;
    return 0;
}
