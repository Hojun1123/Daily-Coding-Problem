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

    int cnt = 0;
    int index = 0;
    while ((index = S.find(f_str, index)) != std::string::npos) {
        cnt ++;
        index++;
    }

    cout << cnt;
    return 0;
}
